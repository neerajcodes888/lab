#include <bits/stdc++.h>
using namespace std;
double GiniIndex(vector<vector<string>> data);
vector<vector<vector<string>>> splitData(vector<vector<string>> data, int column, string value);
vector<vector<vector<string>>> findBestSplit(vector<vector<string>> data, int &bestColumn);
vector<string> getClasses(vector<vector<string>> data);
int findBestColumn(vector<vector<string>> data);
struct Node
{
    string label;
    map<string, Node *> children;
};
Node *buildDecisionTree(vector<vector<string>> data);
void printDecisionTree(Node *node, int indent);
int main()
{
    vector<vector<string>> data = {
        {"Sunny", "Yes", "Rich", "Cinema"},
        {"Sunny", "No", "Rich", "Tennis"},
        {"Windy", "Yes", "Rich", "Cinema"},
        {"Rainy", "Yes", "Poor", "Cinema"},
        {"Rainy", "No", "Rich", "Stay In"},
        {"Rainy", "Yes", "Poor", "Cinema"},
        {"Windy", "No", "Poor", "Cinema"},
        {"Windy", "No", "Rich", "Shopping"},
        {"Windy", "Yes", "Rich", "Cinema"},
        {"Sunny", "No", "Rich", "Tennis"},
    };
    Node *decisionTree = buildDecisionTree(data);
    cout<<"---------------------------------------------------------"<<endl;
    cout <<"********************Decision Tree***********************" << endl;
    cout<<"---------------------------------------------------------"<<endl<<endl;
    printDecisionTree(decisionTree, 0);
}

double GiniIndex(vector<vector<string>> data)
{
    int n = data.size();
    map<string, int> counts;
    for (int i = 0; i < n; i++)
    {
        string label = data[i][data[i].size() - 1];
        counts[label]++;
    }
    double giniIndex = 1;
    for (auto const &it : counts)
    {
        double probability = (double)it.second / n;
        giniIndex -= probability * probability;
    }
    return giniIndex;
}
vector<vector<vector<string>>> splitData(vector<vector<string>> data, int column, string value)
{
    vector<vector<string>> leftData, rightData;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i][column] == value)
        {
            leftData.push_back(data[i]);
        }
        else
        {
            rightData.push_back(data[i]);
        }
    }
    vector<vector<vector<string>>> splitData = {leftData, rightData};
    return splitData;
}
vector<vector<vector<string>>> findBestSplit(vector<vector<string>> data, int &bestColumn)
{
    double bestGiniIndex = 1;
    vector<vector<vector<string>>> bestSplit;
    for (int i = 0; i < data[0].size() - 1; i++)
    {
        vector<string> values;
        for (int j = 0; j < data.size(); j++)
        {
            if (find(values.begin(), values.end(), data[j][i]) == values.end())
            {
                values.push_back(data[j][i]);
            }
        }
        for (int j = 0; j < values.size(); j++)
        {
            vector<vector<vector<string>>> split = splitData(data, i, values[j]);
            double giniIndex = ((double)split[0].size() / data.size()) * GiniIndex(split[0]) + ((double)split[1].size() / data.size()) * GiniIndex(split[1]);
            if (giniIndex < bestGiniIndex)
            {
                bestGiniIndex = giniIndex;
                bestColumn = i;
                bestSplit = split;
            }
        }
    }
    return bestSplit;
}
vector<string> getClasses(vector<vector<string>> data)
{
    vector<string> classes;
    for (int i = 0; i < data.size(); i++)
    {
        if (find(classes.begin(), classes.end(), data[i][data[i].size() - 1]) == classes.end())
        {
            classes.push_back(data[i][data[i].size() - 1]);
        }
    }
    return classes;
}
int findBestColumn(vector<vector<string>> data)
{
    int bestColumn;
    double bestGiniIndex = 1;
    for (int i = 0; i < data[0].size() - 1; i++)
    {
        vector<string> values;
        for (int j = 0; j < data.size(); j++)
        {
            if (find(values.begin(), values.end(), data[j][i]) == values.end())
            {
                values.push_back(data[j][i]);
            }
        }
        double giniIndex = 0;
        for (int j = 0; j < values.size(); j++)
        {
            vector<vector<vector<string>>> split = splitData(data, i, values[j]);
            double probability = (double)split[0].size() / data.size();
            giniIndex += probability * GiniIndex(split[0]);
            probability = (double)split[1].size() / data.size();
            giniIndex += probability * GiniIndex(split[1]);
        }
        if (giniIndex < bestGiniIndex)
        {
            bestGiniIndex = giniIndex;
            bestColumn = i;
        }
    }
    return bestColumn;
}
Node *buildDecisionTree(vector<vector<string>> data)
{
    Node *node = new Node;
    vector<string> classes = getClasses(data);
    if (classes.size() == 1)
    {
        node->label = classes[0];
        return node;
    }
    if (data[0].size() == 1)
    {
        int maxCount = 0;
        string maxClass;
        for (int i = 0; i < classes.size(); i++)
        {
            int count = count_if(data.begin(), data.end(), [classes, i](const vector<string> &v)
                                 { return v[v.size() - 1] == classes[i]; });
            if (count > maxCount)
            {
                maxCount = count;
                maxClass = classes[i];
            }
        }
        node->label = maxClass;
        return node;
    }
    int bestColumn;
    vector<vector<vector<string>>> bestSplit = findBestSplit(data, bestColumn);
    node->label = "Attribute " + to_string(bestColumn) + " = ?";
    vector<string> values;
    for (int i = 0; i < data.size(); i++)
    {
        if (find(values.begin(), values.end(), data[i][bestColumn]) == values.end())
        {
            values.push_back(data[i][bestColumn]);
        }
    }
    for (int i = 0; i < values.size(); i++)
    {
        node->children[values[i]] = buildDecisionTree(splitData(data, bestColumn, values[i])[0]);
    }
    return node;
}
void printDecisionTree(Node *node, int indent)
{
    cout << string(indent, ' ') << node->label << endl;
    for (auto const &it : node->children)
    {
        cout << string(indent + 2, ' ') << it.first << endl;
        printDecisionTree(it.second, indent + 4);
    }
}
