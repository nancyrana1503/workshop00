#pragma once

// Name: Nancy Rana
// Seneca email: nrana18@myseneca.ca
// Seneca Student ID: 149951238
// Date: 12 June 2025
// weapons.h

#ifndef SENECA_WEAPONS_H
#define SENECA_WEAPONS_H

namespace seneca
{
	// for simplicity, the logic associated with the weapons is kept trivial.

	struct BareHands {
		double m_damage = 5;
		operator double() const { return m_damage; }
	};

	struct Sword {
		double m_damage = 20;
		operator double() const { return m_damage; }
	};

	struct Axe {
		double m_damage = 22.5;
		operator double() const { return m_damage; }
	};

	struct Bow {
		double m_damage = 19.2;
		operator double() const { return m_damage; }
	};

	struct Crossbow {
		double m_damage = 56;
		operator double() const { return m_damage; }
	};

	struct Dagger {
		double m_damage = 12.8;
		operator double() const { return m_damage; }
	};
}
#endif
