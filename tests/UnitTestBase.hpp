#ifndef UNIT_TEST_BASE_HPP_INCLUDED
#define UNIT_TEST_BASE_HPP_INCLUDED

#include <iostream>
#include <string>

class UnitTestBase
{
private:
    void resetCounters()
    {
        total_ = 0;
        passed_ = 0;
        failed_ = 0;
    }

protected:
    int total_ = 0;
    int passed_ = 0;
    int failed_ = 0;

    virtual const char *name() const = 0;
    virtual void setUp() {}
    virtual void tearDown() {}
    virtual void executeTests() = 0;

    void recordSuccess(const std::string &msg)
    {
        total_++;
        passed_++;
        std::cout << "[OK] " << msg << std::endl;
    }

    void recordFailure(const std::string &msg)
    {
        total_++;
        failed_++;
        std::cout << "[FALHA] " << msg << std::endl;
    }

    void reportSummary()
    {
        std::cout << name() << ": " << passed_ << "/" << total_ << " testes passaram." << std::endl;
    }

public:
    static const int SUCESSO = 0;
    static const int FALHA = -1;

    int run();
};

int UnitTestBase::run()
{
    resetCounters();
    std::cout << "== " << name() << " ==" << std::endl;
    try
    {
        setUp();
        executeTests();
    }
    catch (const std::exception &ex)
    {
        recordFailure(std::string("Excecao inesperada: ") + ex.what());
    }
    catch (...)
    {
        recordFailure("Excecao inesperada desconhecida");
    }
    tearDown();
    reportSummary();
    return failed_ == 0 ? SUCESSO : FALHA;
}

#endif // UNIT_TEST_BASE_HPP_INCLUDED
