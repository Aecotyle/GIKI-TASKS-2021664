void correlation_matrix::create_signature_vector()
{
    //creating signature vector by given method
    float sum = 0;
    float mean = 0;
    signature_matrix.resize(permute_matrix.size());
    for (int i = 0; i < permute_matrix.size(); i++)
    {
        signature_matrix[i].resize(permute_matrix[0].size());
        for (int j = 0; j < permute_matrix[i].size(); j++)
        {
            sum += permute_matrix[i][j];

        }
        mean = sum /(float) permute_matrix[i].size();
        signature_vector.push_back(sum * mean);

        // signature_matrix[i]=signature_vector;

        sum = 0;
        mean = 0;

    }
}
float findMax(vector<vector<float> > v,int col){
    float max=INT8_MIN*1.0;
    for(int i=0;i<v.size();i++)
        if(v[i][col]>max)
    max=v[i][col];
    return max;
}
void correlation_matrix::create_similarity_matrix()
{
    similarity_matrix.assign(corr_matrix.begin(), corr_matrix.end());
     for(int j=0;j<similarity_matrix[0].size();j++)
     {  float max=findMax(similarity_matrix,j);
        for(int i=0;i<similarity_matrix.size();i++)
           {similarity_matrix[i][j]/=max;
        //    similarity_matrix[i][j]*=255;
           }
     }
}

void correlation_matrix::create_signature_matrix(){

create_signature_vector();
    signature_matrix.assign(similarity_matrix.begin(),similarity_matrix.end());

    for(int i =0;i<signature_matrix.size();i++)
    signature_matrix[i].push_back(signature_vector[i]);

    sort_similarity_matrix();

    for(int j=0;j<signature_matrix[0].size();j++)
     {  float max=findMax(signature_matrix,j);
        for(int i=0;i<signature_matrix.size();i++)
           {signature_matrix[i][j]/=max;
        //    signature_matrix[i][j]*=255;
           }
     }

}

static bool sort_assist(vector<float> & v1,vector<float> &v2){
    return v1[v1.size()-1]<v2[v2.size()-1];
}
void correlation_matrix::sort_similarity_matrix()
{  
    //sorting funciton 
    sort(signature_matrix.begin(), signature_matrix.end(), sort_assist);
}

void correlation_matrix::print_similarity_matrix()
{ 
    //writing genrated output to file
    ofstream f("txtFiles/similarityMatrix.txt");

    for (int i = 0; i < similarity_matrix.size(); i++)
    {
        for (int j = 0; j < similarity_matrix[i].size(); j++)
            f << similarity_matrix[i][j] << ",";
        f << endl;
    }
    f.close();
}
void correlation_matrix::write_signature_matrix_to_file()
{
    //writing genrated output to file
    ofstream f("txtFiles/signatureMatrix.txt");

    for (int i = 0; i < signature_matrix.size(); i++)
    {
        for (int j = 0; j < signature_matrix[i].size(); j++)
            f << signature_matrix[i][j] << ",";
        f << endl;
    }
    f.close();
}
