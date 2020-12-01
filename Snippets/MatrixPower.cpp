struct Matrix
{
    int row, col;
    long long matrix[11][11];
    Matrix(int row_n, int col_n)
    {
        row = row_n;
        col = col_n;
        for(int i = 0;i < row;++i){
            for(int j = 0;j < col;++j)
                matrix[i][j] = 0;
        }
    }

    void set_one()
    {
        for(int i = 0;i < col;++i)
            matrix[i][i] = 1;
    }

    void insert()
    {
        for(int i = 0;i < row;++i){
            for(int j = 0;j < col;++j)
                scanf("%lld", &matrix[i][j]);
        }
    }

    struct Matrix mult(struct Matrix b)
    {
        struct Matrix ret(row, b.col);
        for(int i = 0;i < row;++i){
            for(int j = 0;j < b.col;++j){
                for(int k = 0;k < col;++k){
                    ret.matrix[i][j] += matrix[i][k] * b.matrix[k][j];
                    ret.matrix[i][j] %= mod;
                }
            }
        }

        return ret;
    }

    void print()
    {
        for(int i = 0;i < row;++i){
            for(int j = 0;j < col;++j)
                printf("%lld ", matrix[i][j]);
            putchar('\n');
        }
    }

    struct Matrix matrix_power(Matrix a, long long b)
    {
        if(b == 0)
        {
            Matrix ret(a.row, a.col);
            ret.set_one();
            return ret; 
        }
        if(b == 1)
            return a;
        if(b % 2 == 0)
        {
            Matrix ret = matrix_power(a, b / 2);
            ret = ret.mult(ret);
            return ret;
        }
    
        Matrix ret = matrix_power(a, b - 1);
        ret = ret.mult(a);
        return ret;
    }

};
