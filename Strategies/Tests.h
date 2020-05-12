#ifndef TESTS_H
#define TESTS_H

#include <QTextStream>
#include <QTextCodec>

#include "Strategies/filetypestrategy.h"
#include "Strategies/folderstrategy.h"

class Tests {
public:
    explicit Tests () {
        QTextStream out(stdout);
        out.setCodec(QTextCodec::codecForName("1251"));
        QString test_results_expected[6][2];
        test_results_expected[0][0] = QString::fromUtf8("Heroes-II-of-Might-and-Magic-2-icon.png, size percentage: 99.9442%\nТекстовый файл (1).txt, size percentage: 0.0363711%\nТекстовый файл.txt, size percentage: 0.0193979%\n");
        test_results_expected[1][0] = QString::fromUtf8("Новая папка, size percentage: 0%\nНовая папка (1), size percentage: 20.3378%\nHeroes-II-of-Might-and-Magic-2-icon.png, size percentage: 79.6177%\nТекстовый файл (1).txt, size percentage: 0.028974%\nТекстовый файл.txt, size percentage: 0.0154528%\n");
        test_results_expected[2][0] = QString::fromUtf8(".vs, size percentage: 99.8674%\nTests, size percentage: 0%\nНовая папка, size percentage: 0%\nНовая папка (1), size percentage: 0.0288267%\nНовая папка (2), size percentage: 0.000171811%\nHeroes-II-of-Might-and-Magic-2-icon.png, size percentage: 0.103384%\nTests.lnk, size percentage: 0.000171811%\nТекстовый файл (1).txt, size percentage: 3.76229e-05%\nТекстовый файл.txt, size percentage: 2.00656e-05%\n");
        test_results_expected[3][0] = QString::fromUtf8("The folder is empty.\n");
        test_results_expected[4][0] = QString::fromUtf8("Test5.txt, size percentage: 100%\n");
        test_results_expected[5][0] = QString::fromUtf8("The object doesn\'t exist.\n");
        test_results_expected[0][1] = QString::fromUtf8(".png, size percentage: 99.9442%\n.txt, size percentage: 0.0557691%\n");
        test_results_expected[1][1] = QString::fromUtf8(".png, size percentage: 79.6177%\n.sav, size percentage: 20.2741%\n.txt, size percentage: 0.10817%\n");
        test_results_expected[2][1] = QString::fromUtf8(".db, size percentage: 15.4977%\n.ipch, size percentage: 84.3254%\n.lnk, size percentage: 0.000343623%\n.png, size percentage: 0.103384%\n.sav, size percentage: 0.0287439%\n.suo, size percentage: 0.0443047%\n.txt, size percentage: 0.000140459%\n");
        test_results_expected[3][1] = QString::fromUtf8("The folder is empty.\n");
        test_results_expected[4][1] = QString::fromUtf8(".txt, size percentage: 100%\n");
        test_results_expected[5][1] = QString::fromUtf8("The object doesn\'t exist.\n");
        QString path = QString::fromUtf8("../FileSizeWatcher_Part1/Tests/Test0");
        for (int i = 1; i < 7; i++) {
            switch (i) {
                case 5: {
                    path.append(".txt");
                }
                default: {
                    path[35] = QChar('0' + i);
                }
            }
            out << path << "\n\n";
            strategy = new FolderStrategy();
            QString result = strategy->Explore(path);
            out << result << '\n';
            delete strategy;
            if (result == test_results_expected[i - 1][0]) {
                out << "Test " << i << " passed.\n";
            } else {
                out << "Test " << i << " error.\n";
            }
            strategy = new FileTypeStrategy();
            result = strategy->Explore(path);
            out << '\n' << result << '\n';
            delete strategy;
            if (result == test_results_expected[i - 1][1]) {
                out << "Test " << i << " passed.\n";
            } else {
                out << "Test " << i << " error.\n";
            }
            out << '\n' << flush;
        }
    }
private:
    ExplorerStrategy *strategy;
};

#endif // TESTS_H
