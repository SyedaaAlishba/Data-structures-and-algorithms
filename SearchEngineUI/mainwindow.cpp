#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "SearchEngine.h"

#include <vector>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setStyleSheet(R"(

/* MAIN WINDOW */
QMainWindow {
    background-color: #0B1120;
}

/* TITLE */
QLabel {
    color: white;
    letter-spacing: 1px;
}

/* SEARCH BOX */
QLineEdit {
    background-color: #111827;
    color: white;

    border: 1px solid #1F2937;
    border-radius: 10px;

    padding: 10px 14px;

    font-size: 15px;
    font-family: Segoe UI;
}

QLineEdit:focus {
    border: 1px solid #334155;
}

/* SEARCH BUTTON */
QPushButton {
    background-color: #1E3A8A;
    color: white;

    border: none;
    border-radius: 10px;

    padding: 10px;

    font-size: 14px;
    font-weight: 600;

    min-height: 38px;
}

QPushButton:hover {
    background-color: #2563EB;
}

QPushButton:pressed {
    background-color: #1D4ED8;
}

/* LIST WIDGETS */
QListWidget {
    background-color: #111827;
    color: white;

    border: 1px solid #1F2937;
    border-radius: 10px;

    padding: 6px;

    font-size: 14px;
    outline: none;
}

QListWidget::item {
    padding: 10px;
    border-radius: 6px;
}

QListWidget::item:selected {
    background-color: #1E3A8A;
    color: white;
}

QListWidget::item:hover {
    background-color: #172554;
}

)");

    // LOAD SEARCH ENGINE
    engine.loadDocuments();
    engine.buildIndex();

    vector<Document> docs = engine.getDocuments();

    for (const Document &doc : docs)
    {
        string cleanName =
            doc.filename.substr(doc.filename.find_last_of("\\/") + 1);

        ui->resultBox->addItem(
            QString::fromStdString(cleanName)
            );
    }

    // LIVE AUTOCOMPLETE
    connect(ui->searchBox, &QLineEdit::textChanged,
            this, &MainWindow::onSearchTextChanged);

    connect(ui->searchButton, &QPushButton::clicked,
            this, &MainWindow::onSearchClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ---------------- LIVE SUGGESTIONS ----------------
void MainWindow::onSearchTextChanged(const QString &text)
{
    ui->suggestionBox->clear();

    string prefix = text.toStdString();

    if (prefix.empty())
        return;

    vector<string> suggestions = engine.getSuggestions(prefix);

    for (const string &s : suggestions)
    {
        ui->suggestionBox->addItem(QString::fromStdString(s));
    }
}

// ---------------- SEARCH BUTTON ----------------
void MainWindow::onSearchClicked()
{
    ui->resultBox->clear();

    string query = ui->searchBox->text().toStdString();

    // ✔ USE SINGLE CLEAN PIPELINE
    vector<SearchResult> results = engine.searchWithRanking(query);

    if (results.empty())
    {
        ui->resultBox->addItem("No results found.");
        return;
    }

    for (const SearchResult &r : results)
    {
        string cleanName =
            r.filename.substr(r.filename.find_last_of("\\/") + 1);

        QString item =
            QString::fromStdString(cleanName)
            + " | Score: "
            + QString::number(r.score);

        ui->resultBox->addItem(item);
    }
}