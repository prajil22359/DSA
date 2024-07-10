// precedence graph ko qn ho, providing a schedule that will work with prerequiste condition.
// qn simply asks for a linear ordering -> topological sort to schedule courses.

// input [0,1] means to take course 0, you first need to take course 1. so in precedence graph, an arrow goes from
// 1 -> 0, indicating 1 must come before 0, in our schedule.

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<list>

class Solution {
public:

    void prepAdjList(vector<vector<int>>& prerequisites, unordered_map<int, list<int>>& adjList){
        for(auto i: prerequisites){
            // directed graph obv.
            adjList[i[1]].push_back(i[0]);
        }
    }

    bool dfs(unordered_map<int, list<int>> &adjList,int node, vector<bool> &visited, vector<int> &ans, 
             vector<bool> &activity){
        visited[node]=true;
        activity[node]=true;
        for(auto neighbour: adjList[node]){
            if(activity[neighbour]==true){
                return true;
            }
            if(!visited[neighbour]){
                bool flag = dfs(adjList, neighbour, visited, ans, activity);
                if(flag == true){
                    return true;
                }
            }
        }
        ans.push_back(node);
        activity[node]=false;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adjList;
        vector<bool> visited(numCourses, false);
        vector<bool> activity(numCourses, false);
        vector<int> ans;
        prepAdjList(prerequisites, adjList);
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                bool flag = dfs(adjList, i, visited, ans, activity);

                // cycle present, cant be scheduled.
                if(flag == true){
                    vector<int> emptyArray;
                    return emptyArray;;
                }
            }
        }
        // ans ma prerequisites agadi hunu paryo. ahile maile linear ordering nikale precedence graph ko,
        // a -> b, indicates course a needs course b as prerequisites. so reversing.
        reverse(ans.begin(), ans.end());
        return ans;
    }
};