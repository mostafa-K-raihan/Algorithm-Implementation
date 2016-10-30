#include <bits/stdc++.h>
using namespace std;

void failureFn(string pattern,int patSize, int *failure)
{
    int length = 0; /// previous longest pre-suff
    int i = 1;

    failure [length] = length; /// 0 length er pre-suff keu nai :D
                            //// similar to failure[0] = 0;

    while(i < patSize){
        if(pattern[i] == pattern[length]){
            failure[i++] = ++length;
        }else {
            ///does not match
            if(length != 0){
                ///track back to previous failure value
                length = failure[length - 1];
            }else {
                failure[i++] = 0;
            }
        }
    }

}
void KMP(string haystack, string needle)
{
    int hSize = haystack.size();
    int nSize = needle.size();

    int failure[nSize];
    failureFn(needle, nSize, failure);
    int ptrHaystack, ptrNeedle;

    ptrHaystack = ptrNeedle = 0;

    while(ptrHaystack < hSize)
    {
        if(needle[ptrNeedle++] == haystack[ptrHaystack++]);
        if(ptrNeedle == nSize){
            cout << "Found at " << ptrHaystack - ptrNeedle << endl;
            ptrNeedle = failure[ptrNeedle-1];
        }
        else if(ptrHaystack < hSize && needle[ptrNeedle] != haystack[ptrHaystack]){
            if(ptrNeedle != 0){
                ptrNeedle = failure[ptrNeedle - 1];
            }else {
                ptrHaystack ++;
            }
        }

    }
}



int main()
{
    string pat, txt;
    txt = "AABAACAADAABAAABAA";
    pat = "AABA";
    KMP (txt, pat);
    return 0;
}
