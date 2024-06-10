float correlation_matrix::calculate_mean(int column)
    {
        //function to caluculate mean by adding all values and divinding it by size
        float mean = 0;
        for(int i = 0 ; i < corr_matrix.size() ; i++)
            mean += corr_matrix[i][column]; 

        return (mean/(float)corr_matrix.size());
    }

void correlation_matrix::write_discrete_matrix_to_file()
{
    //writing the generated output to file
    ofstream f("txtFiles/discreteMatrix.txt");
    for (int i = 0; i < discrete_matrix.size(); i++)
    {
        for (int j = 0; j < discrete_matrix[i].size(); j++)
        {
            if (discrete_matrix[i][j] == 1)
                f << "1";
            else
                f << "0";
            f << ",";
        }
        f << endl;
    }
}

void correlation_matrix::create_discrete_matrix()
{
    for (int i = 0; i < discrete_matrix.size(); i++)
    {
        for (int j = 0; j < discrete_matrix.size(); j++)
        {
            //storing discrete values in discrete_matrix depending on calculated mean
            if (corr_matrix[j][i] > calculate_mean(j))
            {
                discrete_matrix[j][i] = 1;
            }
            else
            {
                discrete_matrix[j][i] = 0;
            }
        }
    }
}
