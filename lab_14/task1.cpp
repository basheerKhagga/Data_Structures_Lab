#include <iostream>
using namespace std;

class Router
{

public:
    int data;
    int weight;
    Router *next;
    Router(int gvData = 0, int gvweight = 0, Router *gvnext = nullptr)
    {
        data = gvData;
        weight = gvweight;
        next = gvnext;
    }
    ~Router() {}
};

class Vertice
{

public:
    Router *self;
    Router *root;

    Vertice(int data = -1)
    {
        self = nullptr;
        root = NULL;
    }

    bool insert(int data, int weight = 0)
    {
        if (root == NULL)
        {
            root = new Router(data, weight);
            return true;
        }
        else
        {
            Router *curr = root;
            bool isSame = false;
            if (curr->data == data)
            {
                isSame = true;
            }

            if (isSame == false)
            {
                while (curr->next != NULL)
                {
                    if (curr->next->data == data)
                    {
                        isSame = true;
                        break;
                    }

                    curr = curr->next;
                }
                if (isSame == false)
                {
                    curr->next = new Router(data, weight);
                    return true;
                }
            }
        }

        return false;
    }

    void print()
    {
        Router *curr = root;
        while (curr)
        {
            cout << "\t-> " << curr->data;
            curr = curr->next;
        }
    }
    ~Vertice() {}
};

class Graph
{
private:
    Vertice *array;
    int size;
    int tableSize;
    struct entry
    {
        int dist;
        Router *parent;
        Router *vertex;
    };
    entry *arpTable;
    entry minInTable(int j, Router **minimum, int currSize)
    {

        int min = INT_MAX;
        // Router *temp = arpTable[j].vertex;
        entry toReturn = arpTable[j];
        for (int i = j; i < size; i++)
        {
            if (arpTable[i].dist < min)
            {
                bool isTrue = true;
                for (int k = 0; k < currSize; k++)
                {
                    if (minimum[k])
                        if (minimum[k]->data == arpTable[i].vertex->data)
                        {
                            isTrue = false;
                        }
                }

                if (isTrue)
                {
                    min = arpTable[i].dist;
                    // temp = arpTable[i].vertex;
                    toReturn = arpTable[i];
                }
            }
        }

        return toReturn;
    }


public:
    Graph(int amount = 1)
    {
        if (amount <= 0)
        {
            amount = 1;
        }
        size = amount;
        tableSize = 0;
        array = new Vertice[amount];
        arpTable = new entry[amount];
        for (int i = 0; i < amount; i++)
        {
            arpTable[i] = {INT_MAX, nullptr, nullptr};
        }
    }
    void insertG(int src, int dst, int weight = 1)
    {

        if (src >= size || src < 0)
        {
            cout << "\n[-] SRC or Index is bigger or smaller than size";
            return;
        }

        if (array[src].insert(dst, weight))
        {

            
            if (array[src].self == nullptr)
            {
                array[src].self = new Router(src, -1, array[src].root);
            }
        }
        else
        {
            cout << "\n [-] Error while inserting";
        }

        // if (array[dst].insert(src, weight))
        // {

        //     populated++;
        //     if (array[dst].self == nullptr)
        //     {
        //         array[dst].self = new Router(dst, -1, array[dst].root);
        //     }
        // }
        // else
        // {
        //     cout << "\n [-] Error while inserting";
        // }
    }

    template<class Machine>
    void insertMachine(Machine givenMachine, int givenRouter)
    {
        // Insert machine in machine array
        // Insert machine in current router's routing table

        // Apply dijstra on every router except for given router
        for (int i = 0; i < size; i++)
        {
            if (array[i].self && array[i].self->data != givenRouter)
            {
                printDijstra(i);
            }
            
        }
        

    }

    void printDijstra(int source)
    {

        arpTable[0].dist = 0;
        arpTable[0].vertex = array[source].self;
        // Initialization of Q in dijkstra's algo
        int currentSize = 1;
        for (int j = 1, i = 0; i < size; i++)
        {
            if (i != source && array[i].self != NULL)
            {
                arpTable[j++].vertex = array[i].self;
                currentSize = j;
            }
        }
        tableSize = currentSize;
        // visited list
        Router **visited = new Router *[currentSize];
        for (int i = 0; i < currentSize; i++)
        {
            visited[i] = nullptr;
        }

        int i = 0;
        // while all the elements are not added in visited list traverse
        while (i < currentSize)
        {

            entry minimumEntry = minInTable(0, visited, currentSize); // get minimum dist elemnt from queue
            Router *minimum = minimumEntry.vertex;

            // cout << "\nRetrieved data from min queue: " << minimum->data;
            // Agar visited mai minimum vertex pehlay sy para hova hai to ignore maro
            bool ignore = false;
            for (int j = 0; j < currentSize; j++)
            {
                if (visited[j] == minimum)
                {
                    ignore = true;
                    break;
                }
            }

            if (!ignore)
            {

                // cout << endl
                //      << "Printing visited :  ";
                // for (int k = 0; k < currentSize; k++)
                // {
                //     if (visited[k])
                //     {
                //         cout << "\t" << visited[k]->data;
                //     }
                // }

                Router *temp = minimum;
                temp = temp->next;
                cout << "\n[+] Printing neghbors of vertex : " << minimum->data << " " << i << endl;
                if (minimum->data == 9)
                {
                    cout << endl;
                    Router *curr = minimum;
                    while (curr)
                    {
                        cout << "\t-> " << curr->data;
                        curr = curr->next;
                    }
                }

                while (temp)
                {
                    bool toorDo = false;
                    for (int l = 0; l < currentSize; l++)
                    {
                        if (visited[l])
                            if (temp->data == visited[l]->data)
                            {
                                toorDo = true;
                                break;
                            }
                    }
                    if (toorDo)
                    {
                        temp = temp->next;
                        continue;
                    }

                    cout << "\n Working on vertice " << temp->data;

                    // searching for vertices of a vertex in table
                    int *distOfEdgeInTable = nullptr;
                    Router **parentOfEdgeInTable = nullptr;

                    for (int k = 0; k < currentSize; k++)
                    {
                        if (temp->data == arpTable[k].vertex->data)
                        {

                            distOfEdgeInTable = &arpTable[k].dist;
                            parentOfEdgeInTable = &arpTable[k].parent;
                            break;
                        }
                    }

                    if (distOfEdgeInTable)
                    {

                        if (*distOfEdgeInTable > minimumEntry.dist + temp->weight)
                        {
                            *distOfEdgeInTable = minimumEntry.dist + temp->weight;
                            *parentOfEdgeInTable = minimumEntry.vertex;
                        }
                    }

                    temp = temp->next;
                }

                visited[i] = minimum;
            }

            //   printG();
            i++;
        }
    }

    void printARPTable()
    {
        cout << "\n[+] Printing values of table";
        for (int k = 0; k < tableSize; k++)
        {
            cout << endl
                 << " dist : " << arpTable[k].dist << " Vertex : " << arpTable[k].vertex->data;
            if (arpTable[k].parent)
            {
                cout << " Parent : " << arpTable[k].parent->data;
            }
        }
    }

    void printG()
    {
        for (int i = 0; i < size; i++)
        {
            if (array[i].self)
            {
                cout << endl
                     << array[i].self->data << " : ";
                array[i].print();
            }
        }
    }
    ~Graph() {}
};

int main()
{
    Graph obj(10);
    obj.insertG(9, 1, 3);
    // obj.insertG(1, 9, 3);
    // obj.insertG(1, 8, 6);
    // obj.insertG(8, 1, 4);
    // obj.insertG(9, 8, 1);
    // obj.insertG(8, 9, 2);


    obj.printG();
    obj.printDijstra(9);
    obj.printARPTable();
    return 0;
}