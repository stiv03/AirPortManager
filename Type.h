//
// Created by Stoyan Ivanov on 10.12.24.
//

#ifndef TYPE_H
#define TYPE_H
enum class Type {
    A, B, C
};

std::ostream& operator<<(std::ostream& os, const Type& type);

#endif //TYPE_H
