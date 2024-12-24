# Trading-ROPES (Rapid Order Processing and Execution Solution)

A high-performance order execution and management system built in C++ for Deribit Test platform. This system focuses on providing rapid order processing capabilities with real-time market data integration.

## Project Overview

Trading-ROPES is designed to be a comprehensive trading system that handles:
- Order execution and management
- Real-time market data streaming
- Position management
- High-performance WebSocket server for client connections

## Current Status (As of July 24, 2024)

✅ Day 1 Completed (July 24) 📅:
- Development environment setup
- API connectivity established
- Basic authentication implementation
- Required libraries configured

🚧 In Progress:
- Core order management functions
- WebSocket integration
- Position management features

## Prerequisites

### Required Libraries
- libcurl (HTTP requests)
- Boost.Beast (WebSocket client/server)
- spdlog (Logging)

### Development Tools
- CMake
- G++
- IDE (CLion/VSCode recommended)

## Setup Instructions

1. Clone the repository:
```bash
git clone https://github.com/yourusername/Trading-ROPES.git
cd Trading-ROPES
```

2. Install dependencies (Ubuntu/Debian):
```bash
sudo apt-get update
sudo apt-get install libcurl4-openssl-dev libboost-all-dev
```

3. Build the project:
```bash
mkdir build
cd build
cmake ..
make
```

4. Configure API credentials:
- Create a `config.json` file in the project root
- Add your Deribit Test API credentials:
```json
{
    "api_key": "your_api_key",
    "api_secret": "your_api_secret"
}
```

## Project Timeline

| Phase | Status | Description | Target Completion |
|-------|--------|-------------|-------------------|
| Day 1 | ✅ | Environment Setup & API Connectivity | 📅 December 24, 2024 |
| Day 2 | 🚧 | Core Order Management Functions | 📅 December 25, 2024 |
| Day 3 | 🚧 | WebSocket Market Data Integration | 📅 December 26, 2024 |
| Day 4 | 📅 | WebSocket Server Implementation | 📅 December 27, 2024 |
| Day 5 | 📅 | Position Management Integration | 📅 December 28, 2024 |
| Day 6 | 📅 | Performance Optimization | 📅 December 29, 2024 |
| Day 7 | 📅 | Testing & Documentation | 📅 December 30, 2024 |

## Features (Planned)

- **Order Management** 📅 December 25
  - Place/Modify/Cancel orders
  - Real-time orderbook data
  - Comprehensive error handling

- **Market Data Streaming** 📅 December 26
  - WebSocket integration
  - Real-time market updates
  - Efficient message parsing

- **Client Connectivity** 📅 December 27
  - Multi-threaded WebSocket server
  - Subscription management
  - Real-time data broadcasting

- **Position Management**  December 28-29
  - Real-time position tracking
  - Position updates via WebSocket
  - Integrated risk management

## Contributing

This is currently a personal project in development. Once the initial implementation is complete, contribution guidelines will be provided.

## License

[MIT License](LICENSE)

## Contact

For any queries regarding this project, please open an issue in the repository.

---
⚠️ **Disclaimer**: This project is for educational and testing purposes only. Use at your own risk when connecting to live trading environments.