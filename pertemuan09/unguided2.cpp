/* oleh Liya Khoirunnisa - 2311102124 */
#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;
/// PROGRAM MENU TREE

// Struct pohon
struct Pohon
{
    char data_2124;
    Pohon *left, *right, *parent;
};

// Deklarasi root dan node baru
Pohon *root, *baru;

// Fungsi untuk inisialisasi pohon
void init()
{
    root = NULL;
}

// Fungsi untuk memeriksa apakah pohon kosong
bool isEmpty()
{
    return root == NULL;
}

// Fungsi untuk membuat node root
void buatNode(char data_2124)
{
    if (isEmpty())
    {
        root = new Pohon();
        root->data_2124 = data_2124;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data_2124 << " berhasil dibuat sebagai root." << endl;
    }
    else
    {
        cout << "\nTree sudah ada!" << endl;
    }
}

// Fungsi untuk mencari node berdasarkan data
Pohon *cariNode(char data_2124, Pohon *node = root)
{
    if (!node)
        return NULL;
    if (node->data_2124 == data_2124)
        return node;
    Pohon *leftResult = cariNode(data_2124, node->left);
    if (leftResult)
        return leftResult;
    return cariNode(data_2124, node->right);
}

// Fungsi untuk menambahkan node kiri
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\nNode " << node->data_2124 << " sudah ada child kiri!" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data_2124 = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data_2124 << endl;
            return baru;
        }
    }
}

// Fungsi untuk menambahkan node kanan
Pohon *insertRight(char data_2124, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\nNode " << node->data_2124 << " sudah ada child kanan!" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data_2124 = data_2124;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data_2124 << " berhasil ditambahkan ke child kanan " << node->data_2124 << endl;
            return baru;
        }
    }
}

// Fungsi untuk mengubah data node
void update(char data_2124, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nTidak ada node yang ingin diganti!" << endl;
        }
        else
        {
            char temp_2124 = node->data_2124;
            node->data_2124 = data_2124;
            cout << "\nNode " << temp_2124 << " berhasil diubah menjadi " << data_2124 << endl;
        }
    }
}

// Fungsi untuk mengambil data node
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\nData node: " << node->data_2124 << endl;
        }
    }
}

// Fungsi untuk menemukan data
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\nData Node: " << node->data_2124 << endl;
            cout << "Root: " << root->data_2124 << endl;
            if (!node->parent)
                cout << "Parent: (tidak memiliki parent)" << endl;
            else
                cout << "Parent: " << node->parent->data_2124 << endl;
            if (node->parent != NULL && node->parent->left != node &&
                node->parent->right == node)
                cout << "Sibling: " << node->parent->left->data_2124 << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling: " << node->parent->right->data_2124 << endl;
            else
                cout << "Sibling: (tidak memiliki sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri: (tidak memiliki Child kiri)" << endl;
            else
                cout << "Child Kiri: " << node->left->data_2124 << endl;
            if (!node->right)
                cout << "Child Kanan: (tidak memiliki Child kanan)" << endl;
            else
                cout << "Child Kanan: " << node->right->data_2124 << endl;
        }
    }
}

// Fungsi untuk menampilkan anak-anak dari node
void tampilChild(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\nNode: " << node->data_2124 << endl;
            if (!node->left)
                cout << "Child Kiri: (tidak memiliki Child kiri)" << endl;
            else
                cout << "Child Kiri: " << node->left->data_2124 << endl;
            if (!node->right)
                cout << "Child Kanan: (tidak memiliki Child kanan)" << endl;
            else
                cout << "Child Kanan: " << node->right->data_2124 << endl;
        }
    }
}

// Fungsi untuk menampilkan semua turunan dari node tertentu
void tampilDescendant(Pohon *node)
{
    if (!node)
    {
        cout << "Node yang ditunjuk tidak ada!" << endl;
        return;
    }

    cout << "Turunan dari node " << node->data_2124 << ": ";

    queue<Pohon *> q;
    q.push(node);

    while (!q.empty())
    {
        Pohon *current = q.front();
        q.pop();

        if (current != node)
            cout << current->data_2124 << " ";

        if (current->left)
            q.push(current->left);

        if (current->right)
            q.push(current->right);
    }

    cout << endl;
}

// Penelusuran (Traversal)
// Fungsi preOrder
void preOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data_2124 << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// Fungsi inOrder
void inOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data_2124 << ", ";
            inOrder(node->right);
        }
    }
}

// Fungsi postOrder
void postOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data_2124 << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                if (node->parent->left == node)
                {
                    node->parent->left = NULL;
                }
                else if (node->parent->right == node)
                {
                    node->parent->right = NULL;
                }
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data_2124 << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear()
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    }
    else
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic()
{
    cout << "\nSize Tree: " << size() << endl;
    cout << "Height Tree: " << height() << endl;
    cout << "Average Node of Tree: " << (height() != 0 ? size() / height() : 0) << endl;
}

// Menu interaktif
void menu()
{
    int pilihan_2124;
    char data_2124, dataParent_2124;
    Pohon *node = nullptr;

    do
    {
        cout << "\n===================================================================\n";
        cout << "\t\t\tMENU PROGRAM TREE\n";
        cout << "===================================================================\n";
        cout << "1. Buat Node Root\n";
        cout << "2. Tambah Node Kiri\n";
        cout << "3. Tambah Node Kanan\n";
        cout << "4. Ubah Node\n";
        cout << "5. Retrieve Data\n";
        cout << "6. Temukan Data\n";
        cout << "7. Tampilkan Child Node\n";
        cout << "8. Tampilkan Descendant Node\n";
        cout << "9. PreOrder Traversal\n";
        cout << "10. InOrder Traversal\n";
        cout << "11. PostOrder Traversal\n";
        cout << "12. Karakteristik Tree\n";
        cout << "13. Hapus SubTree\n";
        cout << "14. Hapus Tree\n";
        cout << "0. Keluar\n";
        cout << "-------------------------------------------------------------------\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan_2124;

        switch (pilihan_2124)
        {
        case 1:
            cout << "Masukkan data untuk root: ";
            cin >> data_2124;
            buatNode(data_2124);
            break;
        case 2:
            cout << "Masukkan data untuk node kiri: ";
            cin >> data_2124;
            cout << "Masukkan data parent: ";
            cin >> dataParent_2124;
            node = cariNode(dataParent_2124);
            if (node)
                insertLeft(data_2124, node);
            break;
        case 3:
            cout << "Masukkan data untuk node kanan: ";
            cin >> data_2124;
            cout << "Masukkan data parent: ";
            cin >> dataParent_2124;
            node = cariNode(dataParent_2124);
            if (node)
                insertRight(data_2124, node);
            break;
        case 4:
            cout << "Masukkan data node yang ingin diubah: ";
            cin >> dataParent_2124;
            cout << "Masukkan data node baru: ";
            cin >> data_2124;
            node = cariNode(dataParent_2124);
            if (node)
                update(data_2124, node);
            break;
        case 5:
            cout << "Masukkan data node yang ingin diretrieve: ";
            cin >> dataParent_2124;
            node = cariNode(dataParent_2124);
            retrieve(node);
            break;
        case 6:
            cout << "Masukkan data node yang ingin ditemukan: ";
            cin >> dataParent_2124;
            node = cariNode(dataParent_2124);
            find(node);
            break;
        case 7:
            cout << "Masukkan data node yang ingin ditampilkan anak-anaknya: ";
            cin >> dataParent_2124;
            node = cariNode(dataParent_2124);
            tampilChild(node);
            break;
        case 8:
            cout << "Masukkan data node yang ingin ditampilkan keturunannya: ";
            cin >> dataParent_2124;
            node = cariNode(dataParent_2124);
            tampilDescendant(node);
            break;
        case 9:
            cout << "\nPreOrder Traversal: ";
            preOrder();
            cout << endl;
            break;
        case 10:
            cout << "\nInOrder Traversal: ";
            inOrder();
            cout << endl;
            break;
        case 11:
            cout << "\nPostOrder Traversal: ";
            postOrder();
            cout << endl;
            break;
        case 12:
            characteristic();
            break;
        case 13:
            cout << "Masukkan data node yang ingin dihapus subtreenya: ";
            cin >> dataParent_2124;
            node = cariNode(dataParent_2124);
            deleteSub(node);
            break;
        case 14:
            clear();
            break;
        case 0:
            cout << "Keluar." << endl;
            break;
        default:
            cout << "Pilihan tidak tersedia!" << endl;
            break;
        }
    } while (pilihan_2124 != 0);
}

int main()
{
    menu();
    return 0;
}
