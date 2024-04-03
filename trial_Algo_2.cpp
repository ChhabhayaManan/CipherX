#include <iostream>
using namespace std;
#include <vector>
#include <tuple>

//-------------------------------------------------------------------------//
// This part deals with the implementation of a 3D array using Linked list //
//-------------------------------------------------------------------------//
struct Node
{
    short int row, col, depth;
    bool value;
    Node *next;
};

//------> Inserting a new element in the 3D array
void insert(Node *&head, short int row, short int col, short int depth, bool value)
{
    row -= 1;
    col -= 1;
    depth -= 1;
    Node *newNode = new Node;
    newNode->row = row;
    newNode->col = col;
    newNode->depth = depth;
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

//------> Returns 1 if the element is present in the 3D array
bool getElement(Node *head, short int row, short int col, short int depth)
{
    row -= 1;
    col -= 1;
    depth -= 1;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->row == row && temp->col == col && temp->depth == depth)
            return temp->value;
        temp = temp->next;
    }
    return false;
}

//------> Deleting a node from the 3D array
void deleteNode(Node *&head, short int row, short int col, short int depth)
{
    row -= 1;
    col -= 1;
    depth -= 1;

    Node *temp = head;
    Node *prev = nullptr;

    if (temp != nullptr && temp->row == row && temp->col == col && temp->depth == depth)
    {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != nullptr && (temp->row != row || temp->col != col || temp->depth != depth))
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
        return;

    prev->next = temp->next;
    delete temp;
}

//------> Deleting a slot from the 3D array
void deleteSlot(Node *&head, short int slot)
{
    slot -= 1;
    Node *temp = head;
    Node *prev = nullptr;

    while (temp != nullptr)
    {
        if (temp->col == slot)
        {
            if (temp == head)
            {
                head = temp->next;
                delete temp;
                temp = head;
            }
            else
            {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
}

//-------------------------------------------------------------------------//
//    This part uses 3D array for storing the data of a family members     //
//-------------------------------------------------------------------------//
class Family
{
public:
    Node *head;
    short int membersTotal, slotsTotal, seriesTotal;

    Family()
    {
        head = nullptr;
        membersTotal = 0;
        slotsTotal = 0;
        seriesTotal = 0;
    }
    friend void takeInput(Family &fd);
    friend int countMembers(Family &fd, short int slot, short int series);
    friend vector<tuple<short int, short int, short int>> maxCountMembers(Family &fd);
    friend void deleteSlotSeries(Family &fd, short int slot, short int series);
    friend void deleteMaxCountPairs(Family &fd);
};

//------>> Taking input from the user
void takeInput(Family &fd)
{
    cout << "Members : ";
    cin >> fd.membersTotal;
    cout << "Slots : ";
    cin >> fd.slotsTotal;
    cout << "Series : ";
    cin >> fd.seriesTotal;

    // Taking input from the user
    for (short int i = 1; i <= fd.membersTotal; ++i)
    {
        //cout << "\n================================\n";
        cout << "For Member " << i << " ------>\n";
        short int availSlot, favSeries;

        cout << "Total Favourite Series : ";
        cin >> favSeries;
        short int *arrSeries;
        arrSeries = new short int[favSeries];
        cout << "Enter series : ";
        for (short int k = 0; k < favSeries; ++k)
        {
            cin >> arrSeries[k];
        }

        cout << "Total Available Slots : ";
        cin >> availSlot;
        short int *arrSlots;
        arrSlots = new short int[availSlot];
        cout << "Enter slots : ";
        for (short int j = 0; j < availSlot; ++j)
        {
            cin >> arrSlots[j];
            for (short int k = 0; k < favSeries; ++k)
            {
                insert(fd.head, i, arrSlots[j], arrSeries[k], true);
            }
        }

        //cout << "\n================================\n";

        delete[] arrSeries;
        delete[] arrSlots;
    }
}

//------>> Counting the total number of members for a particular slot and series
int countMembers(Family &fd, short int slot, short int series)
{
    short int count = 0;
    for (short int i = 1; i <= fd.membersTotal; ++i)
    {
        if (getElement(fd.head, i, slot, series))
            count++;
    }
    return count;
}

//------>> Function to delete the slot and series with maximum number of members
void deleteSlotSeries(Family &fd, short int slot, short int series)
{
    // deletes that series from all the slots for all the members that have that slot and series
    for (short int i = 1; i <= fd.membersTotal; ++i)
    {
        for (short int j = 1; j <= fd.slotsTotal; ++j)
        {
            deleteNode(fd.head, i, j, series);
        }
    }
    deleteSlot(fd.head, slot); // deletes that slot from all the members
}

//------>> Function to find the slot and series with maximum number of members and return it as a vector of pairs of 3 that contains slot, series and count
vector<tuple<short int, short int, short int>> maxCountMembers(Family &fd)
{
    short int maxCount = 0;
    vector<tuple<short int, short int, short int>> maxCountPairs;
    maxCountPairs.push_back(make_tuple(-1, -1, -1));
    for (short int i = 1; i <= fd.slotsTotal; ++i)
    {
        for (short int j = 1; j <= fd.seriesTotal; ++j)
        {
            short int count = countMembers(fd, i, j);
            if (count > maxCount)
            {
                maxCount = count;
                maxCountPairs.clear();
                maxCountPairs.push_back(make_tuple(i, j, count));
            }
            //else if the count == maxCount then find the slot, which has minimum sum of countMembers of all series
            else if (count == maxCount)
            {
                short int sum = 0;
                for (short int k = 1; k <= fd.seriesTotal; ++k)
                {
                    sum += countMembers(fd, i, k);
                }
                short int sumMaxCountPairs = 0;
                for (short int k = 0; k < maxCountPairs.size(); ++k)
                {
                    sumMaxCountPairs += get<2>(maxCountPairs[k]);
                }
                if (sum < sumMaxCountPairs)
                {
                    maxCountPairs.clear();
                    maxCountPairs.push_back(make_tuple(i, j, count));
                }
                else if (sum == sumMaxCountPairs)
                {
                    maxCountPairs.push_back(make_tuple(i, j, count));
                }
            }
        }
    }
    return maxCountPairs;
}

//------>> Function that finds maxCountPairs, prints it and then deletes the slot and series of maxCountPairs until no slot and series is left
void deleteMaxCountPairs(Family &fd)
{
    vector<tuple<short int, short int, short int>> maxCountPairs = maxCountMembers(fd);
    cout << endl;
    while (get<2>(maxCountPairs[0]) != -1)
    {
        cout << "slot : " << get<0>(maxCountPairs[0]) << " series : " << get<1>(maxCountPairs[0]) << endl;
        deleteSlotSeries(fd, get<0>(maxCountPairs[0]), get<1>(maxCountPairs[0]));
        maxCountPairs = maxCountMembers(fd);
    }
}

//=========================>> MAIN FUNCTION <<=============================//
int main()
{
    Family fm1;
    takeInput(fm1); 
    deleteMaxCountPairs(fm1);

    return 0;
}