/*
 * This file is part of the PulseView project.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
 * Copyright (C) 2016 Soeren Apel <soeren@apelpie.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#ifndef PULSEVIEW_PV_DATA_SIGNALBASE_HPP
#define PULSEVIEW_PV_DATA_SIGNALBASE_HPP

#include <QColor>
#include <QObject>
#include <QString>

#include <libsigrokcxx/libsigrokcxx.hpp>


namespace sigrok {
class Channel;
class ChannelType;
}

namespace pv {
namespace data {

class SignalBase : public QObject
{
	Q_OBJECT

private:
	static const int ColourBGAlpha;

public:
	SignalBase(std::shared_ptr<sigrok::Channel> channel);
	virtual ~SignalBase() {}

public:
	/**
	 * Returns the underlying SR channel.
	 */
	std::shared_ptr<sigrok::Channel> channel() const;

	/**
	 * Returns enabled status of this channel.
	 */
	bool enabled() const;

	/**
	 * Sets the enabled status of this channel.
	 * @param value Boolean value to set.
	 */
	void set_enabled(bool value);

	/**
	 * Gets the type of this channel.
	 */
	const sigrok::ChannelType *type() const;

	/**
	 * Gets the index number of this channel.
	 */
	unsigned int index() const;

	/**
	 * Gets the name of this signal.
	 */
	QString name() const;

	/**
	 * Sets the name of the signal.
	 */
	virtual void set_name(QString name);

	/**
	 * Get the colour of the signal.
	 */
	QColor colour() const;

	/**
	 * Set the colour of the signal.
	 */
	void set_colour(QColor colour);

	/**
	 * Get the background colour of the signal.
	 */
	QColor bgcolour() const;

Q_SIGNALS:
	void enabled_changed(const bool &value);

	void name_changed(const QString &name);

	void colour_changed(const QColor &colour);

private:
	std::shared_ptr<sigrok::Channel> channel_;
	QString name_;
	QColor colour_, bgcolour_;
};

} // namespace data
} // namespace pv

#endif // PULSEVIEW_PV_DATA_SIGNALBASE_HPP