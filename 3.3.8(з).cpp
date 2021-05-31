#include <iostream>
#include <ctime>

double** get_Init_arr(const int N, const int M)
{
    double** arr = new double*[N];
    for (size_t i = 0; i < N; i++)
    {
        arr[i] = new double[M];
    }
    return arr;
}

void deInit_arr(double** arr, const int N)
{
    for (size_t i = 0; i < N; i++)
    {
        delete[] arr[i];
    }
    delete arr;
}

double** getCreateRandArr(const int N, const int M)
{
    double** arr = get_Init_arr(N, M);
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            arr[i][j] = (double)rand() / 1000;
        }
    }
    return arr;
}

void printArr(double** arr, const int N, const int M)
{
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl << std::endl;
    }
}

double** matrixÑoncatenation(double** arr, const int N, const int M, double** arr_, const int N_)
{
    double** resultArr = get_Init_arr(N + N_, M);
    for (size_t i = 0; i < N_; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            resultArr[i][j] = arr_[i][j];
        }
    }

    for (size_t i = N_, k = 0; i < N + N_ && k < N; i++, k++)
    {
        for (size_t j = 0; j < M; j++)
        {
            resultArr[i][j] = arr[k][j];
        }
    }

    return resultArr;
}

int main()
{   
    srand((unsigned int)(time(NULL)));

    int k;
    int N;
    int M;
    std::cout << "Enter N: ";
    std::cin >> N;
    if (N < 1)
    {
        std::cout << "Uncorrect input. Program exit." << std::endl;
        return 0;
    }
    std::cout << "Enter M: ";
    std::cin >> M;
    if (M < 1)
    {
        std::cout << "Uncorrect input. Program exit." << std::endl;
        return 0;
    }

    double** arr = getCreateRandArr(N, M);
    std::cout << "\nStart arr: " << std::endl;
    printArr(arr, N, M);

    std::cout << "\nEnter k: ";
    std::cin >> k;
    if (N < 0)
    {
        std::cout << "Uncorrect input. Program exit." << std::endl;
        deInit_arr(arr, N);
        return 0;
    }

    double** tempArr = getCreateRandArr(k, M);
    double** resultArr = matrixÑoncatenation(arr, N, M, tempArr, k);

    std::cout << "\n\nResult arr: " << std::endl;
    printArr(resultArr, N + k, M);


    deInit_arr(arr, N);
    deInit_arr(tempArr, k);
    deInit_arr(resultArr, N + k);
    return 0;
}