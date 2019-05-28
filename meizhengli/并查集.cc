const int MAXSIZE = 500;

int uset[MAXSIZE];

int rank[MAXSIZE];

void makeSet(int size)
{

    for (int i = 0; i < size; i++)
        uset[i] = i;
    for (int i = 0; i < size; i++)
        rank[i] = 0;
}
int find(int x)
{
    if (x != uset[x])
        uset[x] = find(uset[x]);
    return uset[x];
}

void unionSet(int x, int y)
{
    if ((x = find(x)) == (y = find(y)))
        return;
    if (rank[x] > rank[y])
        uset[y] = x;

    else
    {

        uset[x] = y;

        if (rank[x] == rank[y])
            rank[y]++;
    }
}