#include "settingswidget.h"

SettingsWidget::SettingsWidget(QWidget *parent) : QWidget(parent)
{
    this->widgetLayout = new QHBoxLayout(this);
    this->algorithmGroupLayout = new QFormLayout();
    this->operatorGroupLayout = new QFormLayout();
    this->populationGroupLayout = new QFormLayout();

    this->algorithmGroup = new QGroupBox("Algorithm Settings");
    this->operatorGroup = new QGroupBox("Operator Settings");
    this->populationGroup = new QGroupBox("Population Settings");

    this->epochCountLabel = new QLabel("Max epochs");
    this->noImprovementLabel = new QLabel("Max no-improvement");
    this->repairChromosomLabel = new QLabel("Repair chromosoms");
    this->crossOperatorLabel = new QLabel("Crossover operator");
    this->crossProbabilityLabel = new QLabel("Crossover probability");
    this->mutOperatorLabel = new QLabel("Mutation opeartor");
    this->mutProbabilityLabel = new QLabel("Mutation probability");
    this->selOperatorLabel = new QLabel("Selection operator");
    this->popSizeLabel = new QLabel("Population size");
    this->newPopSizeLabel = new QLabel("New population size");

    this->epochCountEdit = new QSpinBox();
    epochCountEdit->setRange(SPIN_MIN, SPIN_MAX);
    epochCountEdit->setSingleStep(SPIN_STEP);

    this->noImprovementEdit = new QSpinBox();
    noImprovementEdit->setRange(SPIN_MIN, SPIN_MAX);
    noImprovementEdit->setSingleStep(SPIN_STEP);

    this->crossProbabilityEdit = new QDoubleSpinBox();
    crossProbabilityEdit->setRange(DOUBLE_SPIN_MIN, DOUBLE_SPIN_MAX);
    crossProbabilityEdit->setSingleStep(DOUBLE_SPIN_STEP);

    this->mutProbabilityEdit = new QDoubleSpinBox();
    mutProbabilityEdit->setRange(DOUBLE_SPIN_MIN, DOUBLE_SPIN_MAX);
    mutProbabilityEdit->setSingleStep(DOUBLE_SPIN_STEP);

    this->popSizeEdit = new QSpinBoxEnhenced();
    popSizeEdit->setRange(SPIN_MIN, SPIN_MAX);
    popSizeEdit->setSingleStep(SPIN_STEP);

    this->newPopSizeEdit = new QSpinBoxEnhenced();
    newPopSizeEdit->setRange(SPIN_MIN, SPIN_MAX);
    newPopSizeEdit->setSingleStep(SPIN_STEP);
    connect(popSizeEdit, SIGNAL(valueChanged(int)), newPopSizeEdit, SLOT(setNewMinimum(int)));

    this->crossOperatorBox = new QComboBox();
    crossOperatorBox->addItem("OnePoint");
    crossOperatorBox->addItem("TwoPoint");

    this->mutOperatorBox = new QComboBox();
    mutOperatorBox->addItem("Point Inversion");
    mutOperatorBox->addItem("Segment Inversion");

    this->selOperatorBox = new QComboBox();
    selOperatorBox->addItem("Tournament");
    selOperatorBox->addItem("Roulette");

    this->repairChromosomCheck = new QCheckBox();

    this->runButton = new QPushButton("Run algorithm");
    connect(this->runButton, SIGNAL(released()), this, SLOT(runButtonClicked()));

    algorithmGroupLayout->addRow(epochCountLabel, epochCountEdit);
    algorithmGroupLayout->addRow(noImprovementLabel, noImprovementEdit);

    operatorGroupLayout->addRow(crossOperatorLabel, crossOperatorBox);
    operatorGroupLayout->addRow(crossProbabilityLabel, crossProbabilityEdit);
    operatorGroupLayout->addRow(mutOperatorLabel, mutOperatorBox);
    operatorGroupLayout->addRow(mutProbabilityLabel, mutProbabilityEdit);
    operatorGroupLayout->addRow(selOperatorLabel, selOperatorBox);

    populationGroupLayout->addRow(popSizeLabel, popSizeEdit);
    populationGroupLayout->addRow(newPopSizeLabel, newPopSizeEdit);
    populationGroupLayout->addRow(repairChromosomLabel, repairChromosomCheck);

    algorithmGroup->setLayout(algorithmGroupLayout);
    operatorGroup->setLayout(operatorGroupLayout);
    populationGroup->setLayout(populationGroupLayout);

    widgetLayout->addWidget(algorithmGroup);
    widgetLayout->addWidget(populationGroup);
    widgetLayout->addWidget(operatorGroup);
    widgetLayout->addWidget(this->runButton);


    this->setLayout(widgetLayout);
    this->setFixedHeight(sizeHint().height());
    this->setFixedWidth(sizeHint().width());
}

SettingsWidget::~SettingsWidget()
{
}

void SettingsWidget::runButtonClicked()
{

    printf("Holly shit it works.");
    fflush(NULL);
}