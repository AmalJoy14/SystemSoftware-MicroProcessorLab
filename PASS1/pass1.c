#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void main()
   {
    FILE *source, *optab, *intermediate, *symtab, *length;
    source = fopen("source.txt","r");
    optab = fopen("optab.txt","r");
    intermediate = fopen("intermediate.txt","w");
    symtab = fopen("symtab.txt","w+");
    length = fopen("length.txt","w");                              //To prevent core dumped error
    
    char label[20], opcode[20],operand[20], symtab_data[20], optab_data[20];
    int locctr, starting_address, program_length;
    bool symbol_found, opcode_found;
    
    fscanf(source, "%s%s%s", label, opcode, operand);
    if (strcmp(opcode,"START") == 0)
       {
        starting_address = atoi(operand);
        locctr = starting_address;
        fprintf(intermediate,"\t\t%s\t\t%s\t%s\n", label, opcode, operand);
       }
    else
       {
        locctr = 0;
       }
    fscanf(source,"%s%s%s", label, opcode, operand);
    while (strcmp(opcode, "END") != 0 )
       {
        if (strcmp(label , "**") != 0)
           {
            symbol_found = false;
            rewind(symtab);
            while(!feof(symtab))
               {
                fscanf(symtab, "%s",symtab_data);
                if (strcmp(symtab_data , label ) == 0)
                   {
                    printf("Error : Duplicate Found");
                    symbol_found = true;
                   }
               }
            if (symbol_found == false)
               fprintf(symtab,"%s\t%d\n",label,locctr);
           }
           opcode_found = false;
           rewind(optab);
           while(!feof(optab))
              {
               fscanf(optab, "%s",optab_data);
               if (strcmp(optab_data,opcode) == 0)
                  opcode_found = true;
              }
           fprintf(intermediate,"%d\t",locctr);
           if (opcode_found == true)
               locctr += 3;
           else if(strcmp(opcode,"WORD") == 0)
               locctr += 3;
           else if(strcmp(opcode,"RESW") == 0)
               locctr += 3*atoi(operand);
           else if(strcmp(opcode,"RESB") == 0)
               locctr += atoi(operand);
           else if(strcmp(opcode,"BYTE") == 0)
               locctr += strlen(operand) - 3;
           else
               printf("Error : Invalid Operation Code");
           fprintf(intermediate, "%s\t%s\t%s\n", label, opcode, operand);
           fscanf(source ,"%s%s%s", label, opcode, operand);
       }
    fprintf(intermediate,"%d\t%s\t\t%s\t\t%s\n", locctr, label, opcode, operand);
    program_length = locctr - starting_address;
    printf("Program length : %d\n",program_length);
    fclose(source);
    fclose(optab);
    fclose(intermediate);
    fclose(symtab);
    fclose(length);
   }
   
