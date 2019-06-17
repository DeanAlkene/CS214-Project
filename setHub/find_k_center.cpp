#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <random>
using namespace std;
const int city_num = 656;
const double INF = 1e10;
vector<vector<double>> distMatrix;
vector<int> hubs;
vector<int> assigned_center;
vector<vector<int>> center;

bool cmp(pair<int, int> &left, pair<int, int> &right)
{
    return (left.first > right.first ? true : false);
}

int main()
{
    int hub_num, i, j;
    vector<pair<int, int>> out_degree, in_degree, degree;
    out_degree.resize(city_num, pair<int, int>(0, 0));
    in_degree.resize(city_num, pair<int, int>(0, 0));
    degree.resize(city_num, pair<int, int>(0, 0));
    cout << "Input hub numbers: ";
    cin >> hub_num;

    ifstream csv("tools.csv");
    string row;
    for(i = 0; i < city_num; ++i)
    {
        out_degree[i].second = i + 1;
        in_degree[i].second = i + 1;
        degree[i].second = i + 1;
    }
    getline(csv, row); // Header
    while (getline(csv, row)) {
        istringstream sin(row);
        string field;

        int dep_city, arr_city;
        getline(sin, field, ',');
        dep_city = atoi(field.c_str());
        getline(sin, field, ',');
        arr_city = atoi(field.c_str());
        out_degree[dep_city-1].first++;
        in_degree[arr_city-1].first++;
    }
    for(i = 0; i < city_num; ++i)
    {
        degree[i].first = in_degree[i].first + out_degree[i].first;
    }
    
    csv.close();

    sort(out_degree.begin(), out_degree.end(), cmp);
    sort(in_degree.begin(), in_degree.end(), cmp);
    sort(degree.begin(), degree.end(), cmp);
    for(i = 0; i < hub_num; ++i)
    {
        hubs.push_back(degree[i].second);
    }
    
    int minIndex;
    double minDist;
    ifstream csv_1("dist.csv");
    i = 0;
    distMatrix.resize(city_num);
    assigned_center.resize(city_num+1);
    center.resize(city_num+1);
    while(getline(csv_1, row))
    {
        istringstream sin(row);
        string field;

        double dist;
        while(getline(sin, field, ','))
        {
            dist = atof(field.c_str());
            distMatrix[i].push_back(dist);
        }
        i++;
    }

    csv_1.close();

    cout << "Hubs: " << endl;
    for(i = 0; i < hub_num; ++i)
    {
        cout << hubs[i] << '\t';
    }
    cout << endl;

    for(i = 1; i <= city_num; ++i)
    {
        minIndex = -1;
        minDist = INF;
        
        for(j = 0; j < hub_num; ++j)
        {  
            //cout << i-1 << ' ' << hubs[j]-1 << endl;
            if(distMatrix[i-1][hubs[j]-1] < minDist)
            {
                minIndex = hubs[j];
                minDist = distMatrix[i-1][hubs[j]-1];
            }
        }
        if(i != minIndex)
        {
            assigned_center[i] = minIndex;
            center[minIndex].push_back(i);
        }
    }

    for(i = 0; i < hub_num; ++i)
    {
        cout << hubs[i] << ":" << endl;
        for(j = 0; j < center[hubs[i]].size(); ++j)
        {
            cout << center[hubs[i]][j] << '\t';
        }
        cout << endl;
    }

    return 0;
}