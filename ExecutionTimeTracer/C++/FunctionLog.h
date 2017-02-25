#include <time.h>
#include <thread>

class FunctionLog {
    public:
        FunctionLog(unsigned int _semIntervalID):
        semIntervalID(_semIntervalID) {
            threadID = std::this_thread::get_id();
        }

        void setFunctionStart(timespec val) {
            functionStart = val;
        }

        void setFuncEnd(timespec val) {
            functionEnd = val;
        }

        friend std::ostream& operator<<(std::ostream &os, const FunctionLog &funcLog) {
            os << threadID << ',' << std::to_string(semIntervalID) << ',' 
               << functionStart << ',' << functionEnd << '\n';

            return os;
        }

    private:
        std::thread::id threadID;
        unsigned int semIntervalID;

        timespec functionStart;
        timespec functionEnd;
};

