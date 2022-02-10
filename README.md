 Project by: Kevin Arturo Amaya Osorio

 To compile and execute the code on the 1_Function_Calculator and 2_Variable_Assigning folders use the following command:

    flex calc.l && bison --defines=calc.tab.h calc.y && gcc -o calc -Wall calc.tab.c lex.yy.c -lfl -lm && ./calc


To compile and execute the code on the 4_XML_Grammar folder use the following command:

    flex xml.l && bison --defines=xml.tab.h xml.y && gcc -o xml -Wall xml.tab.c lex.yy.c -lfl -lm && ./xml                                            ─╯
