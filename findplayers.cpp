#include<vector>
#include<iostream>
#include<map>

using namespace std;

//https://leetcode.com/problems/find-players-with-zero-or-one-losses/?envType=daily-question&envId=2024-01-15

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
              vector<int> wins;
            vector<int> loss;
            vector<vector<int>> res;

            map<int,int> winners;
            map<int,int> lossers;

            int n=matches.size();

            for(int i=0;i<n;i++)
            {
                if(winners.find(matches[i][0])==winners.end())
                {
                    winners[matches[i][0]]=1;
                }else{
                    winners[matches[i][0]]++;
                }
                if(lossers.find(matches[i][1])==lossers.end())
                {
                    lossers[matches[i][1]]=1;
                }
                else{
                    lossers[matches[i][1]]++;
                }
            }

            map<int,int>::iterator it =  winners.begin();

            while(it!= winners.end())
            {
                if(lossers.find(it->first)==lossers.end())
                {
                    wins.push_back(it->first);
                }
                it++;
            }

            map<int,int>::iterator it2 = lossers.begin();

            while(it2!=lossers.end())
            {
                if(it2->second==1)
                {
                    loss.push_back(it2->first);
                }
                it2++;
            }

            res.push_back(wins);
            res.push_back(loss);

            return res;

}

int main()
{
  //  vector<vector<int>> matches = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    vector<vector<int>> matches;
    int n;
    cout<<"enter how many matches"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
       
            vector<int> dum;

            int k;
            int g;
            cout<<"enter the winner"<<endl;
            cin>>k;
            dum.push_back(k);
            cout<<"enter the losser"<<endl;
            cin>>g;
            dum.push_back(g);

            matches.push_back(dum);

    }
    vector<vector<int>> res = findWinners(matches);

   cout<<"winners values"<<endl;

   for(int i=0;i<res[0].size();i++)
   {
        cout<<res[0][i]<<" ";
   }cout<<endl;

   cout<<"lossers values"<<endl;
   for(int i=0;i<res[1].size();i++)
    {
        cout<<res[1][i]<<" ";
    }
    cout<<endl;



}