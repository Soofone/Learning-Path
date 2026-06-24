from abc import ABC, abstractmethod
from typing import Any, List, Dict, Union, Optional


class DataProcessor(ABC):

    @abstractmethod
    def process(self, data: Any) -> str:
        pass

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    def format_output(self, result: str) -> str:
        return f"Output: {result}"


class NumericProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        if isinstance(data, bool):
            return False
        elif isinstance(data, (int, float)):
            return True
        elif isinstance(data, List):
            for d in data:
                if isinstance(d, bool):
                    return False
            return all(isinstance(item, (int, float)) for item in data)
        return False

    def process(self, data: Any) -> str:
        if not self.validate(data):
            raise ValueError("Invalid numeric data")
        if isinstance(data, (int, float)):
            data = [data]
        total = sum(data)
        avg = total / len(data)
        return f"Processed {len(data)} numeric values, sum={total}, avg={avg}"

    def format_output(self, result: str) -> str:
        return super().format_output(result)


class TextProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        return isinstance(data, str)

    def process(self, data: Any) -> str:
        if not self.validate(data):
            raise ValueError("Invalid text data")
        chars = len(data)
        words = len(data.split())
        return f"Processed text: {chars} characters, {words} words"

    def format_output(self, result: str) -> str:
        return super().format_output(result)


class LogProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        try:
            valid = isinstance(data, str)
            if not valid:
                return False
            info, msg = data.split(":")
            if not info or not msg:
                raise Exception()
        except Exception:
            raise ValueError("invalid log format")
        return True

    def process(self, data: Any) -> str:
        if not self.validate(data):
            raise ValueError("Invalid log data")
        parts = data.split(":", 1)
        level = parts[0].strip()
        message = parts[1].strip()
        if level.lower() == 'error':
            tag = 'ALERT'
        else:
            tag = 'INFO'
        return f"[{tag}] {level.upper()} level detected: {message}"

    def format_output(self, result: str) -> str:
        return super().format_output(result)


def main() -> None:
    print("=== CODE NEXUS - DATA PROCESSOR FOUNDATION ===")

    try:
        numeric = NumericProcessor()
        print("\nInitializing Numeric Processor...")
        data: List[Union[int, float]] = [1, 2, 3, 4, 5]
        print(f"Processing data: {data}")
        validation_msg = ('Numeric data verified'
                          if numeric.validate(data) else 'Invalid')
        print(f"Validation: {validation_msg}")
        print(numeric.format_output(numeric.process(data)))
    except Exception as e:
        print(e)

    try:
        text = TextProcessor()
        print("\nInitializing Text Processor...")
        data2 = "Hello Nexus World"
        print(f'Processing data: "{data2}"')
        validation_msg = ('Text data verified'
                          if text.validate(data2) else 'Invalid')
        print(f"Validation: {validation_msg}")
        print(text.format_output(text.process(data2)))
    except Exception as e:
        print(e)

    try:
        log = LogProcessor()
        print("\nInitializing Log Processor...")
        data3 = "ERROR: Connection timeout"
        print(f'Processing data: {data3}')
        validation_msg = ('Log entry verified'
                          if log.validate(data3) else 'Invalid')
        print(f"Validation: {validation_msg}")
        print(log.format_output(log.process(data3)))
    except Exception as e:
        print(e)

    print("\n=== Polymorphic Processing Demo ===")
    print("Processing multiple data types through same interface...")

    try:
        processors: Optional[List] = [
            NumericProcessor(),
            TextProcessor(),
            LogProcessor()]

        test_data: Dict = {
            0: [1, 2, 3],
            1: "Hello Nexus.",
            2: "INFO: System ready"
            }

        for i, (processor, datum) in enumerate(
                zip(processors, test_data.values()), 1):
            result = processor.process(datum)
            print(f"Result {i}: {result}")
        print("\nFoundation systems online. Nexus ready for advanced streams.")
    except Exception as e:
        print(e)


if __name__ == "__main__":
    main()
