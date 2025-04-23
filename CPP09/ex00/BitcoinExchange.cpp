#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(){}

int BitcoinExchange::readFromFile(const std::string& filename){
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: Unable to open database file " + filename);
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        addExchangeRate(line);
    }
    file.close();
    return 0;
}

void BitcoinExchange::addExchangeRate(const std::string& line){
    size_t delimiterPos = line.find(',');
    if (delimiterPos == std::string::npos) {
        std::cerr << "Error: Invalid exchange rate format: comma missing" << std::endl;
        return;
    }

    std::string date = line.substr(0, delimiterPos);
    std::string rateStr = line.substr(delimiterPos + 1);

    try {
        checkDate(date);
        double rate = stringToDouble(rateStr);
        exchangeRates[date] = rate;
    } catch (const std::exception& e) {
        std::cerr << "Error: Invalid exchange rate value for date " << date << std::endl;
    }
}

double BitcoinExchange::getExchangeRate(const std::string& date) const{
    std::map<std::string, double>::const_iterator it = exchangeRates.upper_bound(date);
    if (it == exchangeRates.end()) {
        throw std::invalid_argument("Error: Exchange rate not found for date " + date);
    }
    if (it == exchangeRates.begin() && it->first != date) {
        throw std::invalid_argument("Error: Exchange rate not found for date " + date);
    }
    if (it->second < 0.0) {
        throw std::invalid_argument("Error: Exchange rate is negative for date " + date);
    }
    if (static_cast<long long int>(it->second) > static_cast<long long int>(std::numeric_limits<int>::max())) {
        throw std::invalid_argument("Error: Exchange rate is not a valid double for date " + date);
    }
    return it->second;
}

double BitcoinExchange::stringToDouble(const std::string& str) const{
    std::istringstream iss(str);
    double value;
    iss >> value;

    if (iss.fail() || !iss.eof()) {
        throw std::invalid_argument("Error: Invalid double value: " + str);
    }
    return value;
}

int BitcoinExchange::checkDate(const std::string& date) const{
    std::string valid = "0123456789- ";
    const char *dateFormat = "%Y-%m-%d";
    std::tm tm = {};
    if (date.size() < 10 || date.find_first_not_of(valid) != std::string::npos) {
        throw std::invalid_argument("Error: Invalid date format: " + date);
    }
    if (!strptime(date.c_str(), dateFormat, &tm)) {
        throw std::invalid_argument("Error: Invalid date format: " + date);
    }
    int year = tm.tm_year + 1900; // tm_year is years since 1900
    int month = tm.tm_mon + 1; // tm_mon is 0-based
    int day = tm.tm_mday;
    //std::cout << date << ": Year: " << year << ", Month: " << month << ", Day: " << day << std::endl;
    if (year < 2000 || year > 2025 || month < 1 || month > 12 || day < 1 || day > 31) {
        throw std::invalid_argument("Error: Invalid date (year/month/day not valid): " + date);
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        throw std::invalid_argument("Error: Invalid date (day not valid): " + date);
    }
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) { // Leap year
            if (day > 29) {
                throw std::invalid_argument("Error: Invalid date (day not valid): " + date);
            }
        } else {
            if (day > 28) {
                throw std::invalid_argument("Error: Invalid date (day not valid): " + date);
            }
        }
    }
    return 0;
}

void BitcoinExchange::processInput(const std::string& input){
    std::ifstream request(input.c_str());
    if (!request.is_open()) {
        throw std::runtime_error("Error: Unable to open file ");
    }
    std::string line;
    
    while ( std::getline(request, line)) {
        size_t delimiterPos = line.find('|');
        if (delimiterPos == std::string::npos) {
            std::cerr << line << ": Error: Invalid exchange rate format: '|' missing" << std::endl;
            continue;
        }
        std::string date = line.substr(0, delimiterPos - 1);
        std::string amount = line.substr(delimiterPos + 2); // +2 to skip the space
        try {
            checkDate(date);
            double rate = getExchangeRate(date);
            double amountD = stringToDouble(amount);
            if (amountD < 0.0 || amountD > 1000.0) {
                throw std::invalid_argument("Error: Amount is invalid for: " + date);
            }
            std::cout << date << "==> " << rate * amountD << std::endl;
        } catch (const std::exception& e) {
            std::cerr << date << ": " << e.what() << std::endl;
        }
    }
}

BitcoinExchange::BitcoinExchange(BitcoinExchange& cpy){
    *this = cpy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& og){
    if (this != &og) {
        exchangeRates = og.exchangeRates;
    }
    return *this;
}