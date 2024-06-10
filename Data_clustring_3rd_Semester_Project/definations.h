#ifndef DEFINATIONS_H
#define DEFINATIONS_H
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class correlation_matrix
{
    //all private members
     struct node{
        float val;
        bool visited;
        node(){
            val=0;
            visited=false;
        }
     };
    vector<vector<float> > matrix;
    vector<vector<float> > corr_matrix;
    vector<vector<float> > discrete_matrix;
    vector<vector<float> > permute_discrete_matrix;
    vector<vector<float> > permute_corr_matrix;
    vector<vector<float> > permute_matrix;
    vector<vector<float> > similarity_matrix;
    vector<vector<float> > signature_matrix;
    vector<float> signature_vector;
    vector<float> node_weights;
    vector<vector<float> >graph_display_matrix;
    vector<vector<node> >graph;
    vector<bool> bool_v;
    float threshold;
    fstream file;
    int col_size;
    static int count;

public:
    //function prototypes
    correlation_matrix();
    void create_graph();
    void print_cluster(vector<node>&v,float _color=0,int count=0);
    void create_all_clusters_at_once();
    void create_cluster(int count=0);
    float calculate_coefficient(int rows, int columns);
    void create_signature_matrix();
    void write_signature_matrix_to_file();
    void create_coefficent_matrix();
    float calculate_mean(int column);
    void write_discrete_matrix_to_file();
    void create_discrete_matrix();
    void create_permute_matrix();
    void create_signature_vector();
    void create_similarity_matrix();
    void sort_similarity_matrix();
    void print_similarity_matrix();
    void print_signature_vector();
    void write_permute_matrix_to_file();
    void print_permute_factor_matrix();
    void write_correlation_matrix_to_file();
    void create_discrete_matrix_permute();
    float calculate_mean_permute(int column);
    void create_coefficent_matrix_permute(vector<vector<float> > &corr_matrix,vector<vector<float> > &matrix);
    float calculate_coefficient_permute(int rows, int columns,vector<vector<float> > &matrix);


    ~correlation_matrix();
};

//declaring static member
int correlation_matrix::count = 0;

// constructor 
correlation_matrix::correlation_matrix()
{
    threshold = 0.1;
    ifstream file("iris.data");

    if (file.is_open())
    {
        string str;

        while (getline(file, str))
        {
            vector<float> vect;
            stringstream ss(str);
            string str2;

            while (getline(ss, str2, ','))
            {

                try
                {
                    stof(str2);
                }

                catch (const invalid_argument &ia)
                {
                    continue;
                }

                vect.push_back(stof(str2));
            }

            matrix.push_back(vect);
            vect.clear();
        }
        file.close();
    }
    else
    {
        cerr << "Error in opening file!!!";
    }


    matrix.pop_back();
    col_size = matrix[0].size();
    int size = matrix.size();
    corr_matrix.resize(matrix.size());
    discrete_matrix.resize(matrix.size());

    for (int i = 0; i < matrix.size(); i++)
    {
        corr_matrix[i].resize(size);
        discrete_matrix[i].resize(size);

    }
}

//destructor 
correlation_matrix::~correlation_matrix()
{

}
#endif