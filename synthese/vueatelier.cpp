#include <QtGui>

#include "modeleatelier.h"
#include "vueatelier.h"

VueAtelier::VueAtelier(bool isModif, int noAtel, QWidget *parent, Qt::WindowFlags flags) : QDialog(parent, flags) {
    _isModif = isModif;
    _noAtel = noAtel;
    
    init();
    this->setModal(true);
    
    if (_isModif) {
        _model = new ModeleAtelier(_noAtel);
    } else {
        _model = new ModeleAtelier();
    }
    
    fillInfosAtel();
}

VueAtelier::~VueAtelier() {
    delete _lblHeader;
    delete _lblNoAtel;
    delete _lblTitre;
    delete _lblType;
    delete _lblNomExpo;
    delete _lblNomCat;
    delete _lblNbMax;
    delete _lblLangue;
    delete _lblNoLocal;
    delete _lblJour;
    delete _lblHeure;
    delete _lblDuree;
    delete _lblCoutAdulte;
    delete _lblCoutEnfant;
    
    delete _txtNoAtel;
    delete _txtTitre;
    delete _txtNbMax;
    delete _txtCoutAdulte;
    delete _txtCoutEnfant;
    
    delete _cmbType;
    delete _cmbNomExpo;
    delete _cmbNomCat;
    delete _cmbNoLocal;
    delete _cmbJour;
    delete _cmbHeure;
    delete _cmbDuree;
    
    delete _radFrancais;
    delete _radAnglais;
    
    delete _chkAcetate;
    delete _chkRetro;
    delete _chkOrdinateur;
    
    delete _btnAnnuler;
    delete _btnTerminer;
    
    delete _layOptions;
    delete _layBoutons;
    delete _layCentral;
    
    delete _model;
}

void VueAtelier::init() {
    if (_isModif)
        this->setWindowTitle(tr("Modification d'un atelier"));
    else
        this->setWindowTitle(tr("Ajout d'un atelier"));
    
    //Affichage
    _lblHeader = new QLabel(tr("Information sur l'atelier"));
    _lblNoAtel = new QLabel(tr("No d'atelier"));
    _lblTitre = new QLabel(tr("Titre"));
    _lblType = new QLabel(tr("Type"));
    _lblNomExpo = new QLabel(tr("Nom d'exposant"));
    _lblNomCat = new QLabel(tr("Nom Categorie"));
    _lblNbMax = new QLabel(tr("Nb Maximum"));
    _lblNoLocal = new QLabel(tr("No Local"));
    _lblJour = new QLabel(tr("Jour"));
    _lblHeure = new QLabel(tr("Heure"));
    _lblDuree = new QLabel(tr("Duree"));
    _lblCoutAdulte = new QLabel(tr("Cout Adulte"));
    _lblCoutEnfant = new QLabel(tr("Cout Enfant"));
    
    _txtNoAtel = new QLineEdit();
    _txtNoAtel->setEnabled(false);
    _txtTitre = new QLineEdit();
    _txtNbMax = new QLineEdit();
    _txtCoutAdulte = new QLineEdit();
    _txtCoutEnfant = new QLineEdit();
    
    _cmbType = new QComboBox();
    _cmbNomExpo = new QComboBox();
    _cmbNomCat = new QComboBox();
    _cmbNoLocal = new QComboBox();
    _cmbJour = new QComboBox();
    _cmbHeure = new QComboBox();
    _cmbDuree = new QComboBox();
    
    _radFrancais = new QRadioButton(tr("Francais"));
    _radAnglais = new QRadioButton(tr("Anglais"));
    _chkAcetate = new QCheckBox(tr("Acetate Electronique"));
    _chkRetro = new QCheckBox(tr("Retroprojecteur"));
    _chkOrdinateur = new QCheckBox(tr("Ordinateur"));
    
    _btnAnnuler = new QPushButton(tr("Annuler"));
    _btnTerminer = new QPushButton(tr("Terminer"));
    
    _layOptions = new QHBoxLayout();
    _layOptions->addWidget(_radFrancais);
    _layOptions->addWidget(_radAnglais);
    _layOptions->addWidget(_chkAcetate);
    _layOptions->addWidget(_chkRetro);
    _layOptions->addWidget(_chkOrdinateur);
    
    _layBoutons = new QHBoxLayout();
    _layBoutons->addWidget(_btnAnnuler);
    _layBoutons->addWidget(_btnTerminer);
    
    _layCentral = new QGridLayout();
    _layCentral->addWidget(_lblHeader, 0, 0, 1, 4, Qt::AlignCenter);
    _layCentral->addWidget(_lblHeader, 0, 0);
    _layCentral->addWidget(_lblNoAtel, 1, 0);
    _layCentral->addWidget(_txtNoAtel, 1, 1);
    _layCentral->addWidget(_lblNoLocal, 1, 2);
    _layCentral->addWidget(_cmbNoLocal, 1, 3);
    _layCentral->addWidget(_lblTitre, 2, 0);
    _layCentral->addWidget(_txtTitre, 2, 1);
    _layCentral->addWidget(_lblJour, 2, 2);
    _layCentral->addWidget(_cmbJour, 2, 3);
    _layCentral->addWidget(_lblType, 3, 0);
    _layCentral->addWidget(_cmbType, 3, 1);
    _layCentral->addWidget(_lblHeure, 3, 2);
    _layCentral->addWidget(_cmbHeure, 3, 3);
    _layCentral->addWidget(_lblNomExpo, 4, 0);
    _layCentral->addWidget(_cmbNomExpo, 4, 1);
    _layCentral->addWidget(_lblDuree, 4, 2);
    _layCentral->addWidget(_cmbDuree, 4, 3);
    _layCentral->addWidget(_lblNomCat, 5, 0);
    _layCentral->addWidget(_cmbNomCat, 5, 1);
    _layCentral->addWidget(_lblCoutAdulte, 5, 2);
    _layCentral->addWidget(_txtCoutAdulte, 5, 3);
    _layCentral->addWidget(_lblNbMax, 6, 0);
    _layCentral->addWidget(_txtNbMax, 6, 1);
    _layCentral->addWidget(_lblCoutEnfant, 6, 2);
    _layCentral->addWidget(_txtCoutEnfant, 6, 3);
    _layCentral->addLayout(_layOptions, 7, 0, 1, 4);
    _layCentral->addLayout(_layBoutons, 8, 0, 1, 4, Qt::AlignRight);
    
    connect(_btnAnnuler, SIGNAL(clicked()), this, SLOT(reject()));
    connect(_btnTerminer, SIGNAL(clicked()), this, SLOT(valider()));
    
    this->setLayout(_layCentral);
}

void VueAtelier::fillInfosAtel() {
    _txtNoAtel->setText(QString::number(_model->getNoAtel()));
    
    
    _cmbType->insertItems(0, _model->getTypes());
    _cmbNomExpo->insertItems(0, _model->getExposants());
    _cmbNomCat->insertItems(0, _model->getCategories());
    _cmbNoLocal->insertItems(0, _model->getLocaux());
    _cmbJour->insertItems(0, _model->getJours());
    _cmbHeure->insertItems(0, _model->getHeures());
    _cmbDuree->insertItems(0, _model->getDurees());
    
    if (_isModif) {
        _txtTitre->setText(_model->getTitre());
        _txtNbMax->setText(QString::number(_model->getNbMax()));
        _txtCoutAdulte->setText(QString::number(_model->getCoutAdulte()));
        _txtCoutEnfant->setText(QString::number(_model->getCoutEnfant()));
        
        _cmbType->setCurrentIndex(_model->getType() - 1);
        _cmbNomExpo->setCurrentIndex(_model->getNoExpo() - 1);
        _cmbNomCat->setCurrentIndex(_model->getNoCat() - 1);
        _cmbNoLocal->setCurrentIndex(_model->getNoLocal() - 1);
        _cmbJour->setCurrentIndex(_model->getJour());
        _cmbHeure->setCurrentIndex(_model->getHeure() - 10); /* 10h est a l'index 0 */
        
        switch (_model->getDuree()) {
            case 30:
                _cmbDuree->setCurrentIndex(0);
                break;
            case 45:
                _cmbDuree->setCurrentIndex(1);
                break;
            case 60:
                _cmbDuree->setCurrentIndex(2);
                break;
            case 90:
                _cmbDuree->setCurrentIndex(3);
                break;
        }
        
        if (_model->getLangue().toLower() == "f")
            _radFrancais->setChecked(true);
        else
            _radAnglais->setChecked(true);
    }
}

void VueAtelier::valider() {
    this->accept();
}
