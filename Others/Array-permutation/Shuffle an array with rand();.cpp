/*
I saw this idea in this link: https://bost.ocks.org/mike/algorithms/#shuffling
So I decided to make my own Shuffling, with rand();
The shuffling process looks right, but in this code we are trusting in rand(); that's unreliable Pseudorandom number generator.
*/

#include <iostream>
#include <time.h>
using namespace std;

//shuffle/permutation
void shuffle (int v[], int n);
void rearrange(int v[], int n, int d);
void copy_array(int vp[],int v[],int n);

void get_array(int v[],int n);
void print_array(int v[], int n);

int main()
{
    srand(time(NULL)); //create the seed to rand();

    int n;
    cout <<" What is the size of the array you want to permutate: ";
    cin >> n;

    int v[n];

    get_array(v,n);

    cout << "\n\nBefore shuffle : \n";
    print_array(v, n);
    cout << endl << endl;

    shuffle (v, n);
    
    cout << "\n\nAfter shuffle : \n";
    print_array(v, n);
    cout <<"\n\n";

    return 0;
}

void get_array(int v[],int n)
{
    for(int i = 0;i<n;i++){
    cout << "Type the position " << i <<": ";
    cin >> v[i];
    }
}

void print_array(int v[], int n)
{
    for (int i = 0; i < n; i++)
        cout << v[i] << ", ";
}

void shuffle (int v[], int n)
{
    int aux, i = 0, vp[n], aux_n = n;
    for (; aux_n > 0; aux_n--, i++)//to understand this I recommend see this animation: https://bost.ocks.org/mike/algorithms/#shuffling
    {
        aux = rand() % aux_n;
        vp[i] = v[aux];
        rearrange(v, aux_n, aux);//rearrange the array without the position that we 'remove'
       }
      copy_array(vp,v,n);//when is finished, just copy the vp to v
}

void rearrange(int v[], int n, int d)
{
    int aux;
    for (; d < n; d++){
        aux = v[d];          
        v[d] = v[d+1];
        v[d+1] = aux;
    }
}

void copy_array(int vc[],int vt[],int n)
{
for(int i=0; i<n;i++)
        vt[i] = vc[i];
}
