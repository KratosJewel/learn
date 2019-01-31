#pragma once

#include <QtWidgets/QDialog>
#include "ui_example.h"

class Example : public QDialog
{
	Q_OBJECT

public:
	Example(QWidget *parent = Q_NULLPTR);

	void InitSlots();

private slots:
	void OnChkUnderClicked(bool checked);

	void OnChkItalicClicked(bool checked);

	void OnChkBoldClicked(bool checked);

	void SetEditColor();
private:
	Ui::ExampleClass ui;
};
