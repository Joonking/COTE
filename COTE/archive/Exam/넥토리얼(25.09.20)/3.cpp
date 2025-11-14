#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <functional>
#include <cctype>

using namespace std;

string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !isspace(ch);
    }));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), s.end());
    return s;
}

vector<int> networkOptimization(int numRegions, int numConnections, int numTypes, vector<int> fromRegion, vector<int> toRegion, vector<int> connectionType) {
    vector<int> result;

    for (int type = 0; type < numTypes; type++) {
        vector<vector<int>> graph(numRegions);


        for (int i = 0; i < numConnections; i++) {
            if (connectionType[i] != type) {
                graph[fromRegion[i]].push_back(toRegion[i]);
                graph[toRegion[i]].push_back(fromRegion[i]);
            }
        }

        vector<bool> visited(numRegions, false);
        int components = 0;

        for (int i = 0; i < numRegions; i++) {
            if (!visited[i]) {
                components++;

                vector<int> stack;
                stack.push_back(i);

                while (!stack.empty()) {
                    int node = stack.back();
                    stack.pop_back();

                    if (!visited[node]) {
                        visited[node] = true;

                        for (int neighbor : graph[node]) {
                            if (!visited[neighbor]) {
                                stack.push_back(neighbor);
                            }
                        }
                    }
                }
            }
        }

        result.push_back(components);
    }

    return result;
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    string numRegions_temp;
    getline(input, numRegions_temp);
    int numRegions = stoi(ltrim(rtrim(numRegions_temp)));

    string numConnections_temp;
    getline(input, numConnections_temp);
    int numConnections = stoi(ltrim(rtrim(numConnections_temp)));

    string numTypes_temp;
    getline(input, numTypes_temp);
    int numTypes = stoi(ltrim(rtrim(numTypes_temp)));

    string fromRegion_count_temp;
    getline(input, fromRegion_count_temp);
    int fromRegion_count = stoi(ltrim(rtrim(fromRegion_count_temp)));

    vector<int> fromRegion(fromRegion_count);
    for (int i = 0; i < fromRegion_count; i++) {
        string fromRegion_item_temp;
        getline(input, fromRegion_item_temp);
        int fromRegion_item = stoi(ltrim(rtrim(fromRegion_item_temp)));
        fromRegion[i] = fromRegion_item;
    }

    string toRegion_count_temp;
    getline(input, toRegion_count_temp);
    int toRegion_count = stoi(ltrim(rtrim(toRegion_count_temp)));

    vector<int> toRegion(toRegion_count);
    for (int i = 0; i < toRegion_count; i++) {
        string toRegion_item_temp;
        getline(input, toRegion_item_temp);
        int toRegion_item = stoi(ltrim(rtrim(toRegion_item_temp)));
        toRegion[i] = toRegion_item;
    }

    string connectionType_count_temp;
    getline(input, connectionType_count_temp);
    int connectionType_count = stoi(ltrim(rtrim(connectionType_count_temp)));

    vector<int> connectionType(connectionType_count);
    for (int i = 0; i < connectionType_count; i++) {
        string connectionType_item_temp;
        getline(input, connectionType_item_temp);
        int connectionType_item = stoi(ltrim(rtrim(connectionType_item_temp)));
        connectionType[i] = connectionType_item;
    }

    vector<int> result = networkOptimization(numRegions, numConnections, numTypes, fromRegion, toRegion, connectionType);

    for (size_t i = 0; i < result.size(); i++) {
        output << result[i];
        if (i != result.size() - 1) {
            output << "\n";
        }
    }

    output << "\n";

    input.close();
    output.close();

    return 0;
}