#pragma once

#include <QWidget>
#include <QImage>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "ui_ImageCut.h"

namespace JChat {

	class ImageCut : public QWidget
	{
		Q_OBJECT

	public:
		ImageCut(QWidget *parent = Q_NULLPTR);
		~ImageCut();

		static QImage cutImage(QWidget* parent);

	protected:

		Q_SLOT void on_btnOpenFile_clicked();

		Q_SLOT void on_horizontalSlider_valueChanged(int);

		Q_SIGNAL void closed();

		void setImage(QImage const& img);

		QImage getImage() const;

		void closeEvent(QCloseEvent *event) override
		{
			emit closed();
		}

		virtual bool eventFilter(QObject *watched, QEvent *event) override;

		bool isEnableScale() const{ return _initScale < 1 && _item; }
	private:
		Ui::ImageCut ui;

		QGraphicsScene _scene;
		QGraphicsPixmapItem* _item = nullptr;

		double _initScale = 1;
		double _scaleStep = 0;
	};

} // namespace JChat
