int algorithm(int first_value, int second_value)
{
    return first_value + second_value;
}

int fold(int array[], int array_len, int (*sum)(int, int))
{
    int result_sum = array[0];
	if (array_len > 1){
    for (int i = 1; i < array_len - 1; i+=2)
    {
        result_sum += sum(array[i], array[i+1]);
    }
}
    return result_sum;
}

