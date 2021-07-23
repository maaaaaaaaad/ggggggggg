import React from "react";
import styled from "styled-components";

const NaviSearch = () => {
  return (
    <SearchForm>
      <SearchInputText type="text" placeholder="...Search" />
    </SearchForm>
  );
};

const SearchForm = styled.form``;
const SearchInputText = styled.input`
  width: 200px;
  border: 1px solid #807c7c;
  border-radius: 5px;
  outline: none;
`;

export default NaviSearch;