//#include <QCoreApplication>
#include"Parser.h"
#include"Lexer.h"
#include<iostream>
#include<fstream>

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);

//    return a.exec();
    // Lexer
    Lexer lex;
    ifstream t("./asset/source.txt");
    string s((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
    lex.Preprocess(s);
    lex.analyze();
    lex.print("./asset/lex.txt");
    std::cout << "Lex Analysis Done" << '\n';

    Parser parser;
    //parser.readGrammarYACC("./asset/grammar_yacc.txt");
    parser.readGrammar("./asset/grammar.txt");
	parser.printGrammar("./asset/printed_grammar.txt");

    parser.calFirstVN();
	parser.printVNFirst("./asset/firstVN.txt");
    std::cout << "First Done\n";

    parser.constructCluster();
    parser.printCluster("./asset/cluster.txt");
    std::cout << "Cluster Done\n";

    parser.constructTable();
    parser.printTable("./asset/table.txt");
    std::cout << "Table Done\n";


    return 0;
}
