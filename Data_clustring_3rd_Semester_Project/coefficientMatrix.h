
float correlation_matrix::calculate_coefficient(int rows, int columns)
{
    //funciton ot calculate pearson coefficient
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

void correlation_matrix::create_coefficent_matrix()
{
    //intializing  correlation matrix
    for (int i = 0; i < corr_matrix.size(); i++)
    {
        for (int j = 0; j < corr_matrix[i].size(); j++)
        {
            corr_matrix[i][j] = calculate_coefficient(i, j);
        }
    }
}

void correlation_matrix::write_correlation_matrix_to_file()
{
    //write the output generated to file
    ofstream f("txtFiles/coefficientMatrix.txt");
    for (int i = 0; i < corr_matrix.size(); i++)
    {
        for (int j = 0; j < corr_matrix[i].size(); j++)
            f << corr_matrix[i][j] << ",";
        f << endl;
    }
}
