std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (const auto& row : matrix.data) {
        for (const auto& value : row)
            os << value << " ";
        os << "\n";
    }
    return os;
}