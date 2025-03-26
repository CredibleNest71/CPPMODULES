#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(){}

int BitcoinExchange::readFromFile(const std::string& filename){
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: Unable to open file " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        //std::cout << line << std::endl; // Process each line as needed
        addExchangeRate(line);
    }

    file.close();
    return 0; // Return appropriate value if needed
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
        double rate = stringToDouble(rateStr);
        exchangeRates[date] = rate;
        //std::cout << "Date: " << date << ", Rate: " << rate << std::endl;
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

double BitcoinExchange::stringToDouble(const std::string& str) {
    std::istringstream iss(str);
    double value;
    iss >> value;

    if (iss.fail() || !iss.eof()) {
        throw std::invalid_argument("Error: Invalid double value: " + str);
    }
    return value;
}