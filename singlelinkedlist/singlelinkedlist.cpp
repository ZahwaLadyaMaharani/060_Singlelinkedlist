
#include <iostream>
using namespace std;

struct Node
{
    int noMhs;
    string name;
    Node* next;
};

Node* START = null;

void addNode()
{
    int nim;
    string nama;
    Node* nodeBaru = new Node();
    cout << "Masukkan NIM: ";
    cin >> nim;
    cout << "Masukkan Nama: ";
    cin >> nama;
    nodeBaru->noMhs = nim;
    nodeBaru->name = nama;

    if (SATRT == null || nim <= START->noMhs)
    {
        if (START != null && nim == START->noMhs)
        {
            cout << "NIM sudah ada" << endl;
            return;
        }

        nodeBaru->next = START;
        START = nodeBaru;
        return;
    }

    Node* previous = START;
    Node* current = START;

    while ((current != NULL) && (nim >= = current->noMhs))
    {
        if (nim == current->noMhs)
        {
            cout << "NIM sudah ada" << endl;
            return;
        }
        previous->next = current;
        previous->next = nodeBaru;
    }
}

bool searchNode(int nim, Node* current, Node* previous)
{
    previous = START;
    current = START;
    while (current != NULL && nim > current->noMhs)
    {
        previous = current;
        currrent = current->next;
    }

    if (current == null)
    {
        return false;
    }
    else if (current->noMhs == nim)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool deleteNode(int nim)
{
    Node* current = START;
    Node* prevoius = START;
    if (searchNode(nim, prevoius, current) == false)
        return false;
    prevoius->next = current->next;
    if (current == START)
        START = current->next;
    return true;
}
bool listEmpty()
{
    if (START == null)
        return true;
    else
        return false;
}

void traverse()
{
    if (listEmpty())
    {
        cout << "List Kosong" << endl;
        System("pause");
        System("cls");
        return;
    }
    else
    {
        Node* currentNode = START;
        while (currentNode != null)
        {
            cout << "NIM: " << currentNode->noMhs << ", Nama: " << currentNode->name << endl;
            currentNode = currentNode->next;
        }
    }
}

void searchData()
{
    if (listEmpty())
    {
        cout << "List Kosong" << endl;
        System("pause");
        System("cls");
        return;
    }
    else
    {
        int nim;
        cout << "Masukkan NIM: ";
        cin >> nim;
        Node* currentNode = START;
        while (currentNode != null)
        {
            if (currentNode->noMhs == nim)
            {
                cout << "NIM: " << currentNode->noMhs << ", Nama: " << currentNode->name << endl;
                return;
            }
            currentNode = currentNode->next;
        }
        cout << "Data tidak ditemukan" << endl;
    }
}

int main()
{
    int pilihan;
    do
    {
        try
        {

            cout << "1. Tambah Data" << endl;
            cout << "2. Hapus Data" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Cari Data" << endl;
            cout << "5. Keluar" << endl;
            cout << "pilihan: ";
            cin >> pilihan;
            switch (pilihan)
            {
            case 1:
                addNode();
                cout << "Data Berhasil Ditambahkan" << endl;
                System("pause");
                System("cls");
                break;
            case 2:
                if (listEmpty())
                {
                    cout << "List Kosong" << endl;
                    System("pause");
                    System("cls");
                    break;
                }

                int nim;
                cout << "Masukkan NIM: ";
                cin >> nim;
                if (deleteNode(nim))
                {
                    cout << "nim: " << nim << " berhasiol dihapus" << endl;
                    System("pause");
                    System("cls");
                }
                else
                    cout << "Data tidak ditemukan" << endl;
                break;
            case 3:
                traverse();
                break;
            case 4:
                searchData();
                break;
            case 5:
                break;
            default:
                cout << "Pilihan tidak ada" << endl;
            }   break;
        }
        catch (Exception e)
        {
            cout << "Terjadi kesalahan" << endl;
        }

    }
} while (pilihan != 5);
}