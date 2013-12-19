#pragma once

#include <boost/program_options.hpp>

namespace cpuid
{
    namespace po = boost::program_options;

    class commandline_arguments
    {
    public:

        /// Constructor
        commandline_arguments();

        // void
        template<class T>
        void add_option(const char* option,
                        const char* description)
        {
            m_options.add_options()
                (option, po::value<T>(), description);
        }

        po::variables_map parse(int argc, const char *argv[]);

    private:

        /// The options
        po::options_description m_options;
    };

}
