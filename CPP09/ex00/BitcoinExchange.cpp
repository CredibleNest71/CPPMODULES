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
    if (date.size() < 10 || date.find_first_not_of(valid) != std::string::npos) {
        throw std::invalid_argument("Error: Invalid date format: " + date);
    }
    double year = stringToDouble(date.substr(0, 4));
    double month = stringToDouble(date.substr(5, 2));
    double day = stringToDouble(date.substr(8, 2));

    if (year < 2000 || year > 2025 || month < 1 || month > 12 || day < 1 || day > 31) {
        throw std::invalid_argument("Error: Invalid date (year/month/day not valid): " + date);
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
                throw std::invalid_argument("Error: Amount is negative for date: " + date);
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