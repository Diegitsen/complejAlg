#include <bits/stdc++.h>
using namespace std;

class Mochila
{
    private:
        int n;
        int item[3][2];
        int keys[3][2];
        
        
    public:
        Mochila(int n)
        {
            this->n = n;
            for(int i=0; i < 3; i++)
                for(int j= 0; j < 2; j++)
                    keys[i][j]=0;
        }
        
        int getN()
        {
            return n;
        }
        
        void llenar()
        {
            /*
                5 3
                8 5
                2 6
            */
            int a, b;
            
            
            freopen ("in.txt", "r", stdin);
            
            for(int i = 0; i < 3; i++)
            {
                cin >> a >> b;
                item[i][0] = a;
                item[i][1] = b;
            }
        }
        
        void mochilamochila()
        {
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 8; j++)
                {
                    if(item[i][1]<=j)
                    {
                        keys[i][1]=item[i][1];
                        keys[i][0]=item[i][0];
                        if(i==0)
                        {
                            cout << keys[i][0] << " - "; 
                        }
                        
                        else
                        {
                            if(item[i][0]>=keys[i-1][0]) 
                                cout << keys[i][0] << " - ";
                             
                            else
                                cout << keys[i-1][0] << " - ";
                        }
                    }
                   
                    else
                    {
                        for(int i = 0; i < 3; i++)
                        {
                            if(keys[i][1] <= j)
                                {
                                    cout << keys[i][0] << " - ";
                                    break;
                                }
                        }
                    }
                    
                }
                cout << endl;
            }
            
            
        }
};

int main()
{
    Mochila a(3);
    a.llenar();
    a.mochilamochila();
}