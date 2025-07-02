#include<bits/stdc++.h>
using namespace std;

bool match(string s1,string s2){
    int l=s2.length();
    for(int i=0;i<l-1;i++){
        if (s1[i]!=s2[i]){
            if (s1.substr(i,l-i-1)==s2.substr(i+1,l-i-1)) return true;
            return false;
        }
    }
    return true;
}

void search(string s,vector<string >& dic){
    for(auto word:dic){
        if (s==word){
            cout<<s<<" is correct";
            return ;
        }
    }
    cout<<s<<":";
    int l1=s.length();
    int l2;
    for(auto word:dic){
        l2=word.length();
        if (abs(l1-l2)>1) continue;
        if (l1==l2){
            int cnt=0;
            for(int i=0;i<l1;i++){
                if (s[i]!=word[i]) cnt++;
                if (cnt>1) break;
            }
            if (cnt==1) cout<<" "<<word;
        }
        if (l1<l2 && match(s,word)) cout<<" "<<word;
        if (l2<l1 && match(word,s)) cout<<" "<<word;
    }
    return ;
}

int main(){
    string s;
    vector<string > lst;
    cin>>s;
    while(s!="#"){
        lst.push_back(s);
        cin>>s;
    }
    cin>>s;
    while(s!="#"){
        search(s,lst);
        cout<<endl;
        cin>>s;
    }
    return 0;
}