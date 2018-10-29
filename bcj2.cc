#include <iostream>

using namespace std;

int N, M, Q;

int pre[20000], ran[20000];

void makeset(int x)

{

    pre[x] = -1;

    ran[x] = 0;
}

int find(int x)

{

    int r = x;

    while (pre[r] != -1)

        r = pre[r];

    while (x != r)

    {

        int q = pre[x];

        pre[x] = r;

        x = q;
    }

    return r;
}

void unionone(int a, int b)

{

    int t1 = find(a);

    int t2 = find(b);

    if (ran[t1] > ran[t2])

        pre[t2] = t1;

    else

        pre[t1] = t2;

    if (ran[t1] == ran[t2])

        ran[t2]++;
}

int main()

{

    int i, a, b, c, d;

    while (cin >> N >> M)

    {

        for (i = 1; i <= N; i++)

            makeset(i);

        for (i = 1; i <= M; i++)

        {

            cin >> a >> b;

            if (find(a) != find(b))

                unionone(a, b);
        }

        cin >> Q;

        for (i = 1; i <= Q; i++)

        {

            cin >> c >> d;

            if (find(c) == find(d))

                cout << "YES" << endl;

            else

                cout << "NO" << endl;
        }
    }

    return 0;
}