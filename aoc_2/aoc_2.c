#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 1000
#define MAX_COLUMNS 25
#define MAX_LINE 40

//actually using a struct to group it all together
typedef struct {
    int array[MAX_ROWS][MAX_COLUMNS];
    int rows;
    int columns;
} Array2D;

Array2D read_file_to_array(const char* filename) {
    FILE *file;
     //initialize all elements to 0
    Array2D result = {{{0}}, 0, 0};
    char line[MAX_LINE];
    
    file = fopen(filename, "r");


    while (fgets(line, MAX_LINE, file) != NULL && result.rows < MAX_ROWS) {
        result.columns = 0;
        //line is an array of characters, so I guess it makes sense that we're storing line in a ptr?
        char *ptr = line;
        //will hold how many characters we read with sscanf
        int num;
        
        // Parse numbers from the current line
        while (result.columns < MAX_COLUMNS && sscanf(ptr, "%d%n", &result.array[result.rows][result.columns], &num) == 1) {
            //advance to the next index of colums to write new entry to memory
            result.columns++;
            //moves the pointer forward in the string we're trying to read, I think sscanf will return != 1 when it hits non-number
            ptr += num;
        }
        //this just advances to next row
        result.rows++;
    }
    
    fclose(file);
    return result;
}


int main() {
    Array2D data = read_file_to_array("input.txt");
    
    // Now you can use data.array, data.rows, and data.columns
    // For example, to access an element:
    if (data.rows > 0 && data.columns > 0) {
        printf("First number: %d\n", data.array[0][0]);
        printf("Number of rows: %d\n", data.rows);
        printf("Number of columns: %d\n", data.columns);
    }

    return 0;
}