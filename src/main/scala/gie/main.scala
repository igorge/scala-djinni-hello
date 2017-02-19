package gie

import slogging._


object Main extends LazyLogging {
    def main(args: Array[String]): Unit={

        LoggerConfig.factory = PrintLoggerFactory
        LoggerConfig.level = LogLevel.TRACE

        logger.info("main()")

        System.loadLibrary("hello_world_jni")

        val h = HelloWorldMaker.make(34)
        logger.info( s" result = ${h.doHelloWorld("test!")}" )

    }

}
