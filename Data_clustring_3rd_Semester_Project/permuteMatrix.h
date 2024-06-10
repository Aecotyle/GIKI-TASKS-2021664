//corr for permute matrix

float correlation_matrix::calculate_coefficient_permute(int rows, int columns,vector<vector<float> > &matrix)
{
    //calculating pearson coefficient
    float sum_of_x = 0, sum_of_y = 0, sum_of_xy = 0, sum_of_x2 = 0, sum_of_y2 = 0;

    for (int i = 0; i < col_size; i++)
    {
        sum_of_x += matrix[rows][i];
        sum_of_y += matrix[columns][i];
        sum_of_x2 += (matrix[rows][i] * matrix[rows][i]);
        sum_of_y2 += (matrix[columns][i] * matrix[columns][i]);
        sum_of_xy += (matrix[rows][i] * matrix[columns][i]);
    }

    float coef = ((matrix.size() * sum_of_xy) - (sum_of_x * sum_of_y)) / sqrt(((matrix.size() * sum_of_x2) - pow(sum_of_x, 2)) * ((matrix.size() * sum_of_y2) - pow(sum_of_y, 2)));

    return coef;
}

void correlation_matrix::create_coefficent_matrix_permute(vector<vector<float> > &corr_matrix,vector<vector<float> > &matrix)
{
    //creating cofficient permute matrix
    for (int i = 0; i < corr_matrix.size(); i++)
    {
        for (int j = 0; j < corr_matrix[i].size(); j++)
        {
            corr_matrix[i][j] = calculate_coefficient_permute(i, j,matrix);
        }
    }
}


float correlation_matrix::calculate_mean_permute(int column)
    {
        //calculating mean
        float mean = 0;
        for(int i = 0 ; i < permute_matrix.size() ; i++)
            mean += permute_matrix[i][column];

        return (mean/permute_matrix.size());
    }



void correlation_matrix::create_discrete_matrix_permute()
{
    permute_discrete_matrix.resize(matrix.size());
    for (int i = 0; i < matrix.size(); i++)
    {
        permute_discrete_matrix[i].resize(matrix.size());
    }
    for (int i = 0; i < permute_discrete_matrix.size(); i++)
    {
        for (int j = 0; j < permute_discrete_matrix.size(); j++)
        {

            if (permute_corr_matrix[j][i] > calculate_mean_permute(j))
            {
                permute_discrete_matrix[j][i] = 1;
            }
            else
            {
                permute_discrete_matrix[j][i] = 0;
            }
        }
    }

}





void correlation_matrix::create_permute_matrix()
{
    //creating copy of original data matrix to shuffle it and create a permuted matrix
    permute_matrix=matrix;
    permute_corr_matrix.resize(matrix.size());
    for(int i=0;i<matrix.size();i++)
    permute_corr_matrix[i].resize(matrix.size());
    // shuffing 
    for(int i=0;i<permute_matrix.size();i++){
        vector<float> v(permute_matrix[i]);
        int random_index=rand()%permute_matrix.size();
        permute_matrix[i]=permute_matrix[random_index];
        permute_matrix[random_index]=v;

    }
    create_coefficent_matrix_permute(permute_corr_matrix,permute_matrix);
    permute_matrix=permute_corr_matrix;
    create_discrete_matrix_permute(); 
}



void correlation_matrix::write_permute_matrix_to_file()
{
    //writing genrated data to file
    ofstream f("txtFiles/permuteMatrix.txt");
    for (int i = 0; i < permute_discrete_matrix.size(); i++)
    {
        for (int j = 0; j < permute_discrete_matrix[i].size(); j++)
            f << permute_discrete_matrix[i][j] << ",";
        f<< endl;
    }
    f.close();
}






