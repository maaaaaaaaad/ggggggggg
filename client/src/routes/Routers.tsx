import React from "react";
import { Route } from "react-router-dom";
import Books from "../components/Books";
import Home from "../components/Home";
import Login from "../components/Login";
import Notes from "../components/Notes";
import Profile from "../components/Profile";
import ProfileEdit from "../components/Profile/information/ProfileEdit";
import ChangePassword from "../components/Profile/password/ChangePassword";

import SignUp from "../components/SignUp";
import Videos from "../components/Videos";
import SignUpContexts from "../contexts/SignUpContexts";

const Routers = () => {
  //

  return (
    <React.Fragment>
      <Route path="/" exact component={Home} />
      <Route path="/videos" exact component={Videos} />
      <Route path="/books" exact component={Books} />
      <Route path="/notes" exact component={Notes} />
      <Route path="/login" exact component={Login} />

      <SignUpContexts>
        <Route path="/signup" exact component={SignUp} />
        <Route path="/profile/:id/edit" exact component={ProfileEdit} />
        <Route
          path="/profile/:id/change-password"
          exact
          component={ChangePassword}
        />
      </SignUpContexts>

      <Route path="/profile/:id" exact component={Profile} />
    </React.Fragment>
  );
};

export default Routers;
