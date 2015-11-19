#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int vk_bsearch(const int *array, const int start_idx, const int end_idx, const int value) {
	assert(array != NULL);
	assert(start_idx >= 0);
	assert(end_idx >= start_idx);

	if(start_idx == end_idx) {
		if(array[start_idx] > value) return start_idx;
		else return -1;
	}

	const int check_idx = (start_idx + end_idx) / 2;
	if(array[check_idx] <= value) {
		// return vk_bsearch(array, )
		return -1; // TODO
	} else {
		return vk_bsearch(array, check_idx, end_idx, value);
	}
}


int main(int argc, char** argv) {
	if(argc <= 2) {
		printf("Usage: %s <value> <arr_1> <arr_2> <...>\n", argv[0]);
		return 1;
	}

	const int value = atoi(argv[1]);
	const int array_size = argc-2;
	int* array = malloc(array_size*sizeof(int));
	if(array == NULL) {
		printf("Failed to allocate memory\n");
		return 2;
	}

	for(int i = 0; i < array_size; ++i) {
		array[i] = atoi(argv[i+2]);
	}

	const int result = vk_bsearch(array, 0, array_size - 1, value);
	printf("Result: %d\n", result);
	free(array);

	return 0;
}