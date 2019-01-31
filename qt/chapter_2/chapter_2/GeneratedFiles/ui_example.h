/********************************************************************************
** Form generated from reading UI file 'example.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMPLE_H
#define UI_EXAMPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ExampleClass
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QCheckBox *chk_underline_;
    QCheckBox *chk_italic_;
    QCheckBox *chk_bold_;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rbtn_black_;
    QRadioButton *rbtn_red_;
    QRadioButton *rbtn_blue_;
    QHBoxLayout *horizontalLayout_3;
    QPlainTextEdit *edit_text_;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_ok_;
    QPushButton *btn_cancel_;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_exit_;

    void setupUi(QDialog *ExampleClass)
    {
        if (ExampleClass->objectName().isEmpty())
            ExampleClass->setObjectName(QString::fromUtf8("ExampleClass"));
        ExampleClass->resize(317, 256);
        verticalLayout = new QVBoxLayout(ExampleClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(ExampleClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        chk_underline_ = new QCheckBox(groupBox);
        chk_underline_->setObjectName(QString::fromUtf8("chk_underline_"));

        horizontalLayout->addWidget(chk_underline_);

        chk_italic_ = new QCheckBox(groupBox);
        chk_italic_->setObjectName(QString::fromUtf8("chk_italic_"));

        horizontalLayout->addWidget(chk_italic_);

        chk_bold_ = new QCheckBox(groupBox);
        chk_bold_->setObjectName(QString::fromUtf8("chk_bold_"));

        horizontalLayout->addWidget(chk_bold_);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ExampleClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        rbtn_black_ = new QRadioButton(groupBox_2);
        rbtn_black_->setObjectName(QString::fromUtf8("rbtn_black_"));

        horizontalLayout_2->addWidget(rbtn_black_);

        rbtn_red_ = new QRadioButton(groupBox_2);
        rbtn_red_->setObjectName(QString::fromUtf8("rbtn_red_"));

        horizontalLayout_2->addWidget(rbtn_red_);

        rbtn_blue_ = new QRadioButton(groupBox_2);
        rbtn_blue_->setObjectName(QString::fromUtf8("rbtn_blue_"));

        horizontalLayout_2->addWidget(rbtn_blue_);


        verticalLayout->addWidget(groupBox_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        edit_text_ = new QPlainTextEdit(ExampleClass);
        edit_text_->setObjectName(QString::fromUtf8("edit_text_"));

        horizontalLayout_3->addWidget(edit_text_);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btn_ok_ = new QPushButton(ExampleClass);
        btn_ok_->setObjectName(QString::fromUtf8("btn_ok_"));

        horizontalLayout_4->addWidget(btn_ok_);

        btn_cancel_ = new QPushButton(ExampleClass);
        btn_cancel_->setObjectName(QString::fromUtf8("btn_cancel_"));

        horizontalLayout_4->addWidget(btn_cancel_);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        btn_exit_ = new QPushButton(ExampleClass);
        btn_exit_->setObjectName(QString::fromUtf8("btn_exit_"));

        horizontalLayout_4->addWidget(btn_exit_);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(ExampleClass);

        QMetaObject::connectSlotsByName(ExampleClass);
    } // setupUi

    void retranslateUi(QDialog *ExampleClass)
    {
        ExampleClass->setWindowTitle(QApplication::translate("ExampleClass", "Example", nullptr));
        groupBox->setTitle(QApplication::translate("ExampleClass", "GroupBox", nullptr));
        chk_underline_->setText(QApplication::translate("ExampleClass", "Underline", nullptr));
        chk_italic_->setText(QApplication::translate("ExampleClass", "Italic", nullptr));
        chk_bold_->setText(QApplication::translate("ExampleClass", "Bold", nullptr));
        groupBox_2->setTitle(QApplication::translate("ExampleClass", "GroupBox", nullptr));
        rbtn_black_->setText(QApplication::translate("ExampleClass", "Black", nullptr));
        rbtn_red_->setText(QApplication::translate("ExampleClass", "Red", nullptr));
        rbtn_blue_->setText(QApplication::translate("ExampleClass", "Blue", nullptr));
        edit_text_->setPlainText(QApplication::translate("ExampleClass", "Hello.world\n"
"It is my demo.", nullptr));
        btn_ok_->setText(QApplication::translate("ExampleClass", "\347\241\256\345\256\232", nullptr));
        btn_cancel_->setText(QApplication::translate("ExampleClass", "\345\217\226\346\266\210", nullptr));
        btn_exit_->setText(QApplication::translate("ExampleClass", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExampleClass: public Ui_ExampleClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMPLE_H
