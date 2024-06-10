#include "definations.h"
#include "txtfileToBitmap.h"
#include "coefficientMatrix.h"
#include "discreteMatrix.h"
#include "permuteMatrix.h"
#include "similarityMatrix.h"
#include "cluster.h"

class UI
{

private:
    int choise;
    float thresh_hold;
    correlation_matrix mat;

public:
    UI()
    {
    }
    void generateData()
    {
        srand(time(0));
        // computing
        mat.create_coefficent_matrix();
        mat.create_discrete_matrix();
        mat.create_permute_matrix();
        mat.create_similarity_matrix();
        mat.create_signature_matrix();
        mat.create_graph();
        mat.create_cluster();
        // saving results to file
        mat.write_correlation_matrix_to_file();
        mat.write_discrete_matrix_to_file();
        mat.write_permute_matrix_to_file();
        mat.print_similarity_matrix();
        mat.write_signature_matrix_to_file();

        // converting data to images for visualization
        create_bitmap("coefficientMatrix.txt");
        create_bitmap("discreteMatrix.txt");
        create_bitmap("permuteMatrix.txt");
        create_bitmap("similarityMatrix.txt");
        create_bitmap("signatureMatrix.txt");
    }

    void make_menu()
    {
        srand(time(0));
        cout << "Enter a number for the following choise: \n";
        cout << "1. generate correlation matrix\n";
        cout << "2. generate discrete matrix\n";
        cout << "3. generate permute matrix of raw data\n";
        cout << "4. create similarity matrix\n";
        cout << "5. generate signature matrix\n";
        cout << "6. create cluster\n";
        cout << "7. create all of above\n";
        cout << "Enter a number: ";
        cin >> choise;

        while (choise < 1 && choise > 7)
        {
            cerr << "Invalid input enter again: ";
            cin >> thresh_hold;
        }

        while (cin.fail())
        {
            cerr << "Invalid input enter again: ";
            cin >> thresh_hold;
        }

        choise_recieve();
    }

    void choise_recieve()
    {
        switch (choise)
        {
        case 1:
        {

            mat.create_coefficent_matrix();
            // saving results to file
            mat.write_correlation_matrix_to_file();
            // converting data to images for visualization
            create_bitmap("coefficientMatrix.txt");
            break;
        }
        case 2:
        {
            mat.create_discrete_matrix();
            // saving results to file
            mat.write_discrete_matrix_to_file();
            // converting data to images for visualization
            create_bitmap("discreteMatrix.txt");
            break;
        }

        case 3:
        {
            mat.create_permute_matrix();
            // saving results to file
            mat.write_permute_matrix_to_file();
            // converting data to images for visualization
            create_bitmap("permuteMatrix.txt");
            break;
        }
        case 4:
        {
            mat.create_similarity_matrix();
            // saving results to file
            mat.print_similarity_matrix();
            // converting data to images for visualization
            create_bitmap("similarityMatrix.txt");
            break;
        }
        case 5:
        {
            mat.create_signature_matrix();
            mat.write_signature_matrix_to_file();
            // converting data to images for visualization
            create_bitmap("signatureMatrix.txt");
            break;
        }
        case 6:
        {

            cout << "Enter thresh hold value: ";
            cin >> thresh_hold;
            mat.create_graph();
            mat.create_cluster();
            break;
        }

        case 7:
        {
            generateData();
            break;
        }

        default:
        cout<<"Invalid Option!\n";


        }
    }

    ~UI()
    {
    }
};

int main()
{
    UI ui;
    ui.make_menu();

    return 0;
}
