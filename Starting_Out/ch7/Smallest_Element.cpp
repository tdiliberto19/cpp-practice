/**
    Returns the smallest element of an array given its size

    @author Timothy Diliberto
    @version 1.1 4/24/2020
    @param array[] Array to be processed
           size Size of the array
    @return smallest Element with smallest value
*/

int smallestElement(int array[], int size) {
    int smallest = array[0];

    for (int index = 1; index < size; index++) {
        if (array[index] < smallest)
            smallest = array[index];
        index++;
    }

    return smallest;
}
