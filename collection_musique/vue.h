#ifndef __VUE_H__
#define __VUE_H__

#include <QMainWindow>

class QGridLayout;
class QHBoxLayout;
class QLabel;
class QMenu;
class QPushButton;
class QSqlQueryModel;
class QTableView;
class QVBoxLayout;
class QWidget;

class Controleur;
class CustomSqlModel;

class Vue : public QMainWindow {
    Q_OBJECT;
    
    public:
        Vue(Controleur *cont, QWidget *parent = 0);
        ~Vue();
    
    private:
        void init();
        
        QMenu *_mnuFile;
        QMenu *_mnuImport;
        QAction *_actImportCSV;
        QAction *_actImportSQL;
        QAction *_actQuit;
        
        QVBoxLayout *_centralLayout;
        QHBoxLayout *_layBoutons;
        
        QWidget *_centralWidget;
        
        QString _query;
        CustomSqlModel *_model;
        QTableView *_tabView;
        
        QPushButton *_btnList;
        QPushButton *_btnNbAlbums;
        QPushButton *_btnInfos;
        QPushButton *_btnDelete;
        
        private slots:
        void showList();
        void showNbAlbums();
        void showInfos();
        void emptyTable();
        void importCSV();
        void importSQL();
};

#endif //__VUE_H__
