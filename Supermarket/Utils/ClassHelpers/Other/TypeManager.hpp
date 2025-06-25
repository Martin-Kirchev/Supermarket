
#pragma once

enum class WorkerType {

	BASE,
	CASHIER,
	MANAGER

};

inline const char* toString(WorkerType type) {

	switch (type) {

	case WorkerType::BASE: return "BASE";
	case WorkerType::CASHIER: return "CASHIER";
	case WorkerType::MANAGER: return "MANAGER";

	}
}

inline WorkerType workerTypeFromString(const MyString& level) {

	if (level == "BASE") return WorkerType::BASE;
	if (level == "CASHIER") return WorkerType::CASHIER;
	if (level == "MANAGER") return WorkerType::MANAGER;

}

enum class ProductType {

	BY_UNIT,
	BY_WEIGHT

};

inline const char* toString(ProductType type) {

	switch (type) {

	case ProductType::BY_UNIT:  return "BY_UNIT";
	case ProductType::BY_WEIGHT:return "BY_WEIGHT";

	}
}

inline ProductType productTypeFromString(const MyString& type) {

    if (type == "BY_UNIT") return ProductType::BY_UNIT;
    if (type == "BY_WEIGHT") return ProductType::BY_WEIGHT;

}

enum class GiftCardType {

	SINGLE_CATEGORY,
	MULTIPLE_CATEGORY,
	ALL_PRODUCTS

};

inline const char* toString(GiftCardType type) {

	switch (type) {

	case GiftCardType::SINGLE_CATEGORY:    return "SINGLE_CATEGORY";
	case GiftCardType::MULTIPLE_CATEGORY:  return "MULTIPLE_CATEGORY";
	case GiftCardType::ALL_PRODUCTS:       return "ALL_PRODUCTS";

	}
}

inline GiftCardType giftCardTypeFromString(const MyString& type) {

	if (type == "SINGLE_CATEGORY") return GiftCardType::SINGLE_CATEGORY;
	if (type == "MULTIPLE_CATEGORY") return GiftCardType::MULTIPLE_CATEGORY;
	if (type == "ALL_PRODUCTS") return GiftCardType::ALL_PRODUCTS;

}