#include "example.h"

Example::Example(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	InitSlots();
}

void Example::InitSlots()
{
	connect(ui.btn_ok_, SIGNAL(clicked()), this, SLOT(accept()));
	connect(ui.btn_cancel_, SIGNAL(clicked()), this, SLOT(reject()));
	connect(ui.btn_exit_, SIGNAL(clicked()), this, SLOT(close()));

	connect(ui.chk_underline_, SIGNAL(clicked(bool)), this, SLOT(OnChkUnderClicked(bool)));
	connect(ui.chk_italic_, SIGNAL(clicked(bool)), this, SLOT(OnChkItalicClicked(bool)));
	connect(ui.chk_bold_, SIGNAL(clicked(bool)), this, SLOT(OnChkBoldClicked(bool)));

	connect(ui.rbtn_black_, SIGNAL(clicked()), this, SLOT(SetEditColor()));
	connect(ui.rbtn_red_, SIGNAL(clicked()), this, SLOT(SetEditColor()));
	connect(ui.rbtn_blue_, SIGNAL(clicked()), this, SLOT(SetEditColor()));
}

void Example::OnChkUnderClicked(bool checked)
{
	auto cur_font = ui.edit_text_->font();
	cur_font.setUnderline(checked);

	ui.edit_text_->setFont(cur_font);
}

void Example::OnChkItalicClicked(bool checked)
{
	auto cur_font = ui.edit_text_->font();
	cur_font.setItalic(checked);

	ui.edit_text_->setFont(cur_font);
}

void Example::OnChkBoldClicked(bool checked)
{
	auto cur_font = ui.edit_text_->font();
	cur_font.setBold(checked);

	ui.edit_text_->setFont(cur_font);
}

void Example::SetEditColor()
{
	auto cur_palette = ui.edit_text_->palette();

	if (ui.rbtn_black_->isChecked())
	{
		cur_palette.setColor(QPalette::Text, Qt::black);
	}
	else if (ui.rbtn_red_->isChecked())
	{
		cur_palette.setColor(QPalette::Text, Qt::red);
	}
	else if (ui.rbtn_blue_->isChecked())
	{
		cur_palette.setColor(QPalette::Text, Qt::blue);
	}

	ui.edit_text_->setPalette(cur_palette);
}