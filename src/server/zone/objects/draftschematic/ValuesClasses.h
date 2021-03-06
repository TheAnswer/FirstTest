/*
Copyright (C) 2007 <SWGEmu>

This File is part of Core3.

This program is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software
Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Linking Engine3 statically or dynamically with other modules
is making a combined work based on Engine3.
Thus, the terms and conditions of the GNU Lesser General Public License
cover the whole combination.

In addition, as a special exception, the copyright holders of Engine3
give you permission to combine Engine3 program with free software
programs or libraries that are released under the GNU LGPL and with
code included in the standard release of Core3 under the GNU LGPL
license (or modified versions of such code, with unchanged license).
You may copy and distribute such a system following the terms of the
GNU LGPL for Engine3 and the licenses of the other code concerned,
provided that you include the source code of that other code when
and as the GNU LGPL requires distribution of source code.

Note that people who make modified versions of Engine3 are not obligated
to grant this special exception for their modified versions;
it is their choice whether to do so. The GNU Lesser General Public License
gives permission to release a modified version without this exception;
this exception also makes it possible to release a modified version
which carries forward this exception.
*/

#ifndef VALUESCLASSES_H_
#define VALUESCLASSES_H_

#include "engine/engine.h"

/*
 * The Values class is just a container for values calculated in crafting
 * Each "Value" has 3 properties, maxPercentage, currentPercentage, currentValue.
 * These values coupled with the traits minValue and maxValue allow a generic holder for
 * whatever value the crafting process needs on any range
 */
class Values {
	VectorMap<String, float> values;
	String name;
	float minValue, maxValue;
	int precision;
	bool locked;
	bool experimentalProperties;

public:
	Values(const String& n, const float& tempmin, const float& tempmax, const int& prec, const bool& filler) {
		name = n;

		minValue = tempmin;
		maxValue = tempmax;
		precision = prec;

		locked = false;

		values.put("maxPercentage", 0.0f);
		values.put("currentPercentage", 0.0f);
		values.put("currentValue", 0.0f);

		experimentalProperties = filler;
	}

	~Values(){
		values.removeAll();
	}

	inline float getPercentage() {
		return values.get("currentPercentage");
	}

	inline float getValue() {
		return values.get("currentValue");
	}

	inline float getMaxPercentage() {
		return values.get("maxPercentage");
	}

	inline float getMinValue() {
		return minValue;
	}

	inline float getMaxValue() {
		return maxValue;
	}

	inline int getPrecision() {
		return precision;
	}

	inline bool isFiller() {
		return experimentalProperties;
	}

	inline String& getName() {
		return name;
	}

	inline void lockValue() {
		minValue = getValue();
		maxValue = getValue();
		locked = true;
	}

	inline void setValue(const float& value) {
		if (locked)
			return;
		if (values.contains("currentValue")) {
			values.drop("currentValue");
		}

		if (values.contains("currentPercentage")) {
			values.drop("currentPercentage");
		}

		float newpercentage;

		if (maxValue > minValue)
			newpercentage = (value - minValue) / (maxValue - minValue);
		else
			newpercentage = 1 - ((value - maxValue) / (minValue - maxValue));

		values.put("currentValue", value);
		values.put("currentPercentage", newpercentage);
	}

	inline void setMinValue(const float& value) {
		if (locked)
			return;
		minValue = value;
	}

	inline void setMaxValue(const float& value) {
		if (locked)
			return;
		maxValue = value;
	}

	inline void setPrecision(const int& value) {
		if (locked)
			return;
		precision = value;
	}

	inline void setMaxPercentage(const float& value) {
		if (locked)
			return;
		if (values.contains("maxPercentage")) {
			values.drop("maxPercentage");
		}

		values.put("maxPercentage", value);
	}

	inline void setPercentage(const float& value) {
		if (locked)
			return;
		if (values.contains("currentPercentage")) {
			values.drop("currentPercentage");
		}

		values.put("currentPercentage", value);
	}
	inline void resetValue() {
		float reset = (getMaxPercentage() * 10.0f) * (0.000015f * (getMaxPercentage() * 10.0f) + 0.015f);
		setPercentage(reset);

		float newvalue;
		if (maxValue > minValue)
			newvalue = (reset * (maxValue - minValue)) + minValue;
		else
			newvalue = ((1.0f - reset) * (minValue - maxValue)) + maxValue;
		setValue(newvalue);
	}

};

class Subclasses {
	VectorMap<String, Values*> valueList;
	float avePercentage;
	String name, classTitle;

	bool hidden;

public:
	Subclasses(const String& title, const String& subtitle, const float
			min, const float max, const int precision, const bool filler) {

		classTitle = title;

		name = subtitle;

		Values* values = new Values(subtitle ,min, max, precision, filler);

		valueList.setNullValue(NULL);
		valueList.put(subtitle, values);

		if(classTitle == "null" || classTitle == "" || (name == "")) {
			hidden = true;
		}
		else
			hidden = false;
	}

	~Subclasses(){
		for (int i = 0; i < valueList.size(); ++i)
			delete valueList.get(i);

		valueList.removeAll();
	}

	void addSubtitle(const String& s, const float min, const float max, const int precision, const bool filler) {

		if (valueList.contains(s)) {
			valueList.drop(s);
		}

		Values* values = new Values(s, min, max, precision, filler);
		valueList.put(s, values);
	}

	inline Values* get(const int i){
		return valueList.get(i);
	}

	inline Values* get(const String& subTitle) {
		return valueList.get(subTitle);
	}

	inline int size(){
		return valueList.size();
	}

	inline bool isClassHidden(){
		return hidden;
	}

	inline float getPercentage(const String& subTitle) {
		Values* values = valueList.get(subTitle);
		return values->getPercentage();
	}

	inline float getMaxPercentage(const String& subTitle) {
		Values* values = valueList.get(subTitle);
		return values->getMaxPercentage();
	}

	inline float getValue(const String& subTitle) {
		Values* values = valueList.get(subTitle);
		return values->getValue();
	}

	//inline String& getName() {
	//	return name;
	//}

	inline String& getClassTitle() {
		return classTitle;
	}

	inline void setMaxPercentage(const String& subtitle, const float value) {
		Values* values = valueList.get(subtitle);
		values->setMaxPercentage(value);

	}

	inline void setValue(const String& subtitle, const float value) {
		Values* values = valueList.get(subtitle);
		values->setValue(value);
	}

	inline void setPercentage(const String& subtitle, const float value) {
		Values* values = valueList.get(subtitle);
		values->setPercentage(value);
	}

	void toString(){
		Values* tempValues;

		for (int i = 0;i < valueList.size(); ++i) {

			tempValues = valueList.get(i);

			System::out << "Property Name: " << tempValues->getName();

			if(tempValues->isFiller()) {
				System::out << " HIDDEN" << endl;
			} else {
				System::out << endl;
			}

			System::out << "Max % " << tempValues->getMaxPercentage() << endl;
			System::out << "Current % " << tempValues->getPercentage() << endl;
			System::out << "Current Value " << tempValues->getValue() << endl;
			System::out << "Min " << tempValues->getMinValue() << " max " << tempValues->getMaxValue() << endl;
		}
	}
};

#endif /*VALUESCLASSES_H_*/
